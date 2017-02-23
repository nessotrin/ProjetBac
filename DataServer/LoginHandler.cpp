#include "LoginHandler.h"

#include "Logger.h"


#include <cstring>
#include <cstdlib>
#include <cstdio>


LoginHandler::LoginHandler()
{
	/* Initialisation */
	clientList = NULL;
	clientCount = 0;
	iteratorCounter = 0;
}

/***
S'occupe d'un nouveau socket venant de se connecter:
Il crée un nouveau client, s'occupe du 'login' et l'ajoute à la liste
***/
bool LoginHandler::addNewClient(int socket)
{
	Logger::log("Start connection protocol on the client ...\n");

	/* Crée un nouveau client avec le 'socket' donné*/
	Client * newClient = new Client(socket);
	
	/* Lance la procédure de 'login' */
	if(loginProtocol.doLogin(newClient)) /* Si échec, le client est supprimé et l'opération abandonée*/
	{
		delete(newClient); 
		return true;
	}
	
	/* La liste des clients est étendue*/
	clientCount++;
	clientList = (Client **) realloc(clientList,clientCount*sizeof(Client*));
	
	/* Le nouveau client est ajouté */
	clientList[clientCount-1] = newClient;
	
	Logger::log("Now at %d clients !\n",clientCount);
	
	return false;
}


/***
La fonction déconnecte tout les clients possédant le socket donné (les sockets sont EN THEORIE unique à chaque client)
Le client est ensuite supprimé
***/
void LoginHandler::disconnect(int socket)
{
	Logger::log("Disconnecting socket %d ...\n", socket);
	
	/* Passage dans la liste des clients */
	for(int i = 0 ; i < clientCount ; i++)
	{
		/* Comparaison */
		if(clientList[i]->getSocket() == socket)
		{
			//DO CLIENT PROTOCOL HERE
			/* Appel pour retirer de la liste le client numéro 'i' */
			removeFromList(i);
			break;
		}
	}
	
	//GLOBAL DO PROTOCOL HERE
}

/***
Permet d'itérer sur les sockets de tous les clients
L'appelant donne un pointeur dans lequel sera placé le socket
La fonction retourne 'True' tant que tout les sockets ne sont pas passés
***/
bool LoginHandler::iterateOnSockets(int * socketToUse)
{
	/* Vérification de la progression */
	if(iteratorCounter >= clientCount) /* Tout les sockets ont été visités */
	{
		/* Retour à 0 */
		iteratorCounter = 0;
		/* On préviens que tout à été traversé */
		return false;
	}
	else
	{
		/* On place le socket */
		*socketToUse = clientList[iteratorCounter]->getSocket();
		/* On avance d'un */
		iteratorCounter++;
		/* On préviens de continuer*/
		return true;
	}
}

/***
Permet d'itérer sur les client de tous les clients
L'appelant donne un pointeur de pointeur dans lequel sera placé le pointeur vers le client
La fonction retourne 'True' tant que tout les clients ne sont pas passés
***/
bool LoginHandler::iterateOnClients(Client ** clientToUse)
{
	Logger::log("Iterating on clients at %d/%d\n",iteratorCounter,clientCount);

	/* Vérification de la progression */
	if(iteratorCounter >= clientCount)
	{
		/* Retour à 0 */
		iteratorCounter = 0;
		/* On préviens que tout à été traversé */
		return false;
	}
	else
	{
		/* On place le pointeur vers le client */
		*clientToUse = clientList[iteratorCounter];
		/* On avance d'un */
		iteratorCounter++;
		/* On préviens de continuer*/
		return true;
	}
}


void LoginHandler::removeFromList(int id)
{
	/* On remet le compteur d'itérateur en arrière dans le cas où l'on est entrain d'itérer */
	if(iteratorCounter > id) //move the iterator back if it's currently counting inside the moved zone
	{
		iteratorCounter--;
	}
	
	/* Supprime le client */
	delete(clientList[id]);
	
	/* Comble le trou dans la liste */
	memmove(clientList+id,clientList+id+1,clientCount-id-1);
	
	/* Réduit la taille de la liste (sans modifier la taille allouée, elle sera changé à la prochaine connection d'un client)*/
	clientCount--;
}