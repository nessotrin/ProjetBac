#include "LoginHandler.h"

#include <cstring>
#include <cstdlib>
#include <cstdio>

LoginHandler::LoginHandler()
{
	clientList = NULL;
	clientCount = 0;
	iteratorCounter = 0;
}

int LoginHandler::addNewClient(int socket)
{
	//DO PROTOCOL HERE
	
	
	printf("%d\n",clientList);
	
	clientCount++;
	clientList = (Client **) realloc(clientList,clientCount*sizeof(Client*));
	
	clientList[clientCount-1] = new Client(socket);
}

int LoginHandler::disconnect(int socket)
{

	for(int i = 0 ; i < clientCount ; i++)
	{
		if(clientList[i]->getSocket() == socket)
		{
			//DO CLIENT PROTOCOL HERE
			removeFromList(i);
		}
	}

	//GLOBAL DO PROTOCOL HERE
	
}

int LoginHandler::iterateOnSockets(int * socketToUse)
{
	if(iteratorCounter >= clientCount)
	{
		iteratorCounter = 0;
		return 0;
	}
	else
	{
		*socketToUse = clientList[iteratorCounter]->getSocket();
		return 1;
	}
}



void LoginHandler::removeFromList(int id)
{
	if(iteratorCounter > id) //move the iterator back if it's currently counting inside the moved zone
	{
		iteratorCounter--;
	}
	
	memmove(clientList+id,clientList+id+1,clientCount-id-1); //CHECK ARGS ORDER

}