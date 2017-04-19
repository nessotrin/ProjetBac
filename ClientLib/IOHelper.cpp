#include "IOHelper.h"

#include <unistd.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <unistd.h>//sleep		

/***
Fonction raccourcie pour envoyer un message et avoir une requête
***/
char * IOHelper::sendRequestAndGetRequest(int clientSocket, char * requestBuffer)
{
	/* Envoie la requête */
	if(sendRequest(clientSocket,requestBuffer))
	{
		return NULL;
	}
	
	/* Reçoie une réponse */
	return getRequest(clientSocket);
}

/***
Récupère des données du socket UNIX et coupe à la première fin de ligne
Les octets sont lus un par un et ajoutés à la requête reçue, si il s'agit d'un retour à la ligne, il s'arrête
***/
char * IOHelper::getRequest(int clientSocket)
{
	/* Création du buffer */
	char * buffer = NULL;
	/* Mise en place des compteurs*/
	int bufferSize = 0;
	int bufferPos = 0;
	int tryCount = 0;
	do
	{
		/* Si il n'y a plus de place dans la requête */
		if(bufferPos == bufferSize)
		{
			/* On la réaloue avec 20 caractères de plus*/
			bufferSize += 20;
			buffer = (char *) realloc(buffer, bufferSize);
			if(buffer == NULL) /* Si la réalocation échoue */
			{
				printf("ALLOC ERROR !\n");
				return NULL;
			}
		}
		/* On lit un octet et on l'ajoute au buffer */
		int readSize = read(clientSocket, buffer+bufferPos, 1);

		if(readSize <= 0)
		{
			tryCount++;
			if(tryCount > 10)
			{
				if(tryCount == 11)
				{
					printf("Reseau lent !\n");
				}
				usleep(10000); // delai de 10ms
			}
			
			if(tryCount > 1000)
			{
				printf("ERREUR DE RECEPTION /!\\\n");
				return NULL; //abandon
			}
		}
		bufferPos += readSize;
	} while(bufferPos == 0 || buffer[bufferPos-1] != '\n'); /*On vérifie qu'il ne s'agisse pas d'une fin de ligne*/

	/* On donne le buffer qui contient le requête reçue */
	return buffer;
}

/***
Envoie une requête sur le socket UNIX
Il envoie les octets le plus vite possible et s'arrête quand le message est complet
***/
bool IOHelper::sendRequest(int clientSocket, char * requestBuffer)
{
	int length = strlen(requestBuffer);
	int writePos = 0;
	int tryCount = 0;
	while(writePos != length)
	{
		int writeSize = write(clientSocket, requestBuffer+writePos, length-writePos);
		if(writeSize <= 0) // erreur ou plus de place
		{
			tryCount++;
			if(tryCount > 10)
			{
				if(tryCount == 11)
				{
					printf("Reseau lent !\n");
				}
				usleep(10000); // delai de 10ms
			}
			
			if(tryCount > 1000)
			{
				printf("ERREUR D'ENVOI /!\\\n");
				return true; //abandon
			}
		}
		writePos += writeSize;
	}
	return false;
}

