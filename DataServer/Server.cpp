#include "Server.h"

#include "Logger.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <netinet/in.h>
#include <unistd.h>



Server::Server(int newPort, LoginHandler * newLoginHandler, RequestHandler * newRequestHandler)
{
	/* Copie des valeurs d'initialisation */
	port = newPort;
	requestHandler = newRequestHandler;
	loginHandler = newLoginHandler;
}

/***
Ajoute les sockets 'UNIX' au sélecteur d'attente 'UNIX'
***/
int Server::addSocketsToSelector()
{
	//clear the socket set
	FD_ZERO(&selector);
	//add master socket to set
	FD_SET(serverSocket, &selector);
	int max_sd = serverSocket;
	//add child sockets to set
	int socket;
	
	/* Boucle sur les sockets */
	while (loginHandler->iterateOnSockets(&socket)) 
	{
		if(socket > 0) //if valid socket descriptor then add to read list
		{
			FD_SET(socket, &selector);			
		}
		
		if(socket > max_sd) //highest file descriptor number, need it for the select function
		{
			max_sd = socket;			
		}
	}
	
	return max_sd;
}

/***
Accepte un client et lui donne un socket
***/
void Server::acceptClient()
{
	Logger::log("New client connecting ...\n",InfoLog);
	
	/* Création du socket et acceptation */
	struct sockaddr_in address;
	int addrlen = 0;
	int newSocket = accept(serverSocket, (struct sockaddr *)&address, (socklen_t*)&addrlen);
	if(newSocket < 0) /* Vérification de réussite */
	{
		Logger::log("ERROR on accept\n",ErrorLog);
		/* Abandon */
		return;
	}
	
	/* Ajout du client au handler des clients */
	if(loginHandler->addNewClient(newSocket)) /* Vérification de l'échec, érreur réseau ou serveur plein */
	{
		Logger::log("SERVER FULL or CONNECTION FAILED\n",WarningLog);
		/* Ferme le nouveau socket*/
		close(newSocket);
		/* Abandon */
		return;
	}
	
	Logger::log("Client fully connected !\n",InfoLog);
}

/***
Gère les clients
**/
void Server::handleClients()
{
	//Logger::log("Handling clients ...\n",InfoLog);
	Client * client;
	
	int id;
	/* Boucle sur les clients */
	for(int i = 0 ; i < loginHandler.getClientCount() ; i++) 
	{
		client = loginHandler.getClient(i);
//		Logger::log("Checking socket ...\n",InfoLog);
		/* On vérifie si il se passe quelque chose sur le socket */
		if(FD_ISSET(client->getSocket(), &selector)) /* Il se passe quelque chose */
		{
			//Logger::log("Socket triggered\n",InfoLog);
			/* Gestion de la requête */
			if(requestHandler->triageRequest(client)) /* Vérification de l'échec*/
			{
				Logger::log("Socket handling failed\n",WarningLog);
				/* On déconnecte le client */
				loginHandler->disconnect(client->getSocket());
			}
		}
		//Logger::log("Socket checked ...\n",InfoLog);
	}
}

void Server::work()
{
	while(1)
	{
		//Logger::log("Setting up selector ... \n",InfoLog);
		/* On ajoute les sockets 'UNIX' au selecteur 'UNIX' */
		int max_sd = addSocketsToSelector();
		//Logger::log("Set'ed up ! \n",InfoLog);
		
		Logger::log("Waiting for activity on sockets ...\n",InfoLog);
		//wait for an activity on one of the sockets , timeout is NULL , so wait indefinitely
        /* On attends que quelque chose se passe */
		int activity = select( max_sd + 1 , &selector , NULL , NULL , NULL);
        if(activity < 0)
        {
            Logger::log("ERROR on select\n",WarningLog);
        }
		
		  
        //If something happened on the master socket , then its an incoming connection
		/* Si le socket serveur est prêt, c'est qu'un client attends */
        if(FD_ISSET(serverSocket, &selector)) 
        {
			/* On acceuille le client */
			acceptClient();
        }
		/* Sinon, on regarde sur les sockets des clients*/
		else
		{
			/* On gère les clients */
			handleClients();
		}			
		//Logger::log("Activity loop restarting ... \n",InfoLog);
	}
}

/***
On initialise le serveur en créant le socket de récepetion, en le paramétrant et en le 'bind'-ans au port
***/
bool Server::setup()
{
	retry:
	
	/* Création de la variable des paramètres et du socket internet */
	struct sockaddr_in serverAddr;
	serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (serverSocket < 0) /* Vérification de l'échec */ 
	{
		Logger::log("ERROR opening socket\n",ErrorLog);
		/* Abandon */
		return true;
	}

	/* Paramétrage de la variable des paramètres*/
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = INADDR_ANY;
	serverAddr.sin_port = htons(port);


	Logger::log("Binding port ...\n",InfoLog);

	/* Demande à l'OS de bind' le socket sur le port*/
	if (bind(serverSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) < 0) /* Vérification d'échec */
	{
		Logger::log("ERROR Couldn't bind port !\nIs or was a server already running ?\nRetrying ...\n",WarningLog);
		sleep(5);
		goto retry;
		/* Abandon */
		return true;
	}
	
	/* Demande à l'OS d'ouvrir le socket aux connections */
	if(listen(serverSocket,3) < 0) /* Vérification d'échec */
	{
		Logger::log("ERROR while setting to listening mode\n",ErrorLog);
		/* Abandon */
		return true;
	}
	

	return false;
}