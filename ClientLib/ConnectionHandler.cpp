#include "ConnectionHandler.h"

#include <netinet/in.h>
#include <cstdio>
#include <cstring>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

/***
Création d'un socket 'unix' et connection au serveur
Le socket est crée, paramétré et connecté
***/
bool ConnectionHandler::connectToIP(char * ip, int port)
{
	printf("Connecting to \"%s\" ...\n",ip);
	
	/* Crée la variable de l'adresse */
    struct sockaddr_in serverAddr;

	/* Domande à l'OS un socket réseau */
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket < 0)
	{
		printf("ERROR opening socket !");
		return true;
	}
	/* Paramètre le socket */
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr(ip);
    serverAddr.sin_port = htons(port);
	
	/* Connecte le socket */
    if (connect(clientSocket,(struct sockaddr *) &serverAddr,sizeof(serverAddr)) < 0)
	{
		printf("FAILED TO CONNECT !\n");
		return true;
	}
	

	/* Met le socket en mode non bloquant */
	fcntl(clientSocket, F_SETFL, fcntl(clientSocket, F_GETFL, 0) | O_NONBLOCK);
	
	printf("Sucessfully connected !\n");
	
    return false;
}

/***
S'identifie au serveur, donne ses informations et passe le 'challenge'
Le challenge est le mot de passe '<3COOKIE'
***/
bool ConnectionHandler::doLogin(ModuleInfo info)
{
	/* Crée le message et y place les informations conformément à la spécification*/
	char buffer[64]; 
	memcpy(buffer,"<3COOKIE",8);
	buffer[8] = info.type;
	buffer[9] = info.versionMajor;
	buffer[10] = info.versionMinor;
	buffer[11] = info.versionPatch;
	buffer[12] = info.isDebug;
	
	/* Envoie le message dans le socket */
	if(write(clientSocket,buffer,64) != 64)
	{
		printf("Failed to sent login message !\n");
		return true;
	}
	
	printf("Loggin'ed ! \n");
	return false;
}

/***
Acceseurs de la class
***/
int ConnectionHandler::getSocket()
{
	return clientSocket;
}

/***
Coupe la connection et rend le socket à l'OS
***/
void ConnectionHandler::disconnect()
{
	close(clientSocket);
}

bool ConnectionHandler::checkForData()
{
	int count;
	ioctl(clientSocket, FIONREAD, &count);
	return (count > 0);
}