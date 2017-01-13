#include "Server.h"


#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <netinet/in.h>
#include <unistd.h>



Server::Server(int newMaxClients, int newPort)
{
	maxClients = newMaxClients;
	port = newPort;
}

int Server::addToClientList(int socket)
{
	//add new socket to array of sockets
	for(int i = 0; i < maxClients; i++) 
	{
		//if position is empty
		if(clientSockets[i] == 0)
		{
			clientSockets[i] = socket;
			printf("New client added with id %d\n" , i);
			return i;
		}
	}
	return -1;
}

int Server::removeFromClientList(int socket)
{
	//add new socket to array of sockets
	for(int i = 0; i < maxClients; i++) 
	{
		//if position is empty
		if(clientSockets[i] == socket)
		{
			clientSockets[i] = 0;
			printf("Removed client with id %d\n" , i);
			return i;
		}
	}
	return -1;
}
int Server::addSocketsToSelector()
{
	//clear the socket set
	FD_ZERO(&selector);
	//add master socket to set
	FD_SET(serverSocket, &selector);
	int max_sd = serverSocket;
	//add child sockets to set
	for (int i = 0 ; i < maxClients ; i++) 
	{
		if(clientSockets[i] > 0) //if valid socket descriptor then add to read list
		{
			FD_SET(clientSockets[i], &selector);			
		}
		
		if(clientSockets[i] > max_sd) //highest file descriptor number, need it for the select function
		{
			max_sd = clientSockets[i];			
		}
	}
	
	return max_sd;
}

void Server::acceptClient()
{
	struct sockaddr_in address;
	int addrlen;
	int newSocket = accept(serverSocket, (struct sockaddr *)&address, (socklen_t*)&addrlen);
	if(newSocket < 0)
	{
		printf("ERROR on accept\n");
		return;
	}
	
	if(addToClientList(newSocket) < 0)
	{
		printf("SERVER FULL\n");
		close(newSocket);
	}
}

int Server::answerToClient(int clientSocket)
{
	char buffer[1024];
	int bufferLength = read(clientSocket , buffer, 1024);
	printf("read %dB\n",bufferLength);
	return bufferLength;
}

void Server::work()
{
	while(1)
	{
		int max_sd = addSocketsToSelector();
		
		//wait for an activity on one of the sockets , timeout is NULL , so wait indefinitely
        int activity = select( max_sd + 1 , &selector , NULL , NULL , NULL);
        if(activity < 0)
        {
            printf("ERROR on select\n");
        }
		
		  
        //If something happened on the master socket , then its an incoming connection
        if(FD_ISSET(serverSocket, &selector)) 
        {
			acceptClient();
        }
		else
		{
			//else its some IO operation on some other socket :)
			for (int i = 0; i < maxClients ; i++) 
			{				  
				if(FD_ISSET(clientSockets[i] , &selector)) 
				{
					if(answerToClient(clientSockets[i]) == 0)
					{ // disconnected
						removeFromClientList(clientSockets[i]);
					}
				}
			}
		}			

	}
}

bool Server::setup()
{
	clientSockets = (int *) calloc(maxClients,sizeof(int));
	if(clientSockets == NULL)
	{
		printf("ERROR allocation failed (ClientSockets, %d)",maxClients);
		return true;
	}
	
	
	struct sockaddr_in serverAddr;

	serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (serverSocket < 0) 
	{
		printf("ERROR opening socket\n");
		return true;
	}

	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = INADDR_ANY;
	serverAddr.sin_port = htons(port);

	if (bind(serverSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) < 0)
	{
		printf("ERROR Couldn't bind port !\nIs a server already running ?\n");
		return true;
	}
	
	if(listen(serverSocket,3) < 0)
	{
		printf("ERROR while setting to listening mode\n");
		return true;
	}
	

	return false;
}