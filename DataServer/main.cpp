#include "server.h"

#include <stdio.h>

#include <cstring>
#include <netinet/in.h>
#include <fcntl.h>
#include <unistd.h>

#define VERSION_MAJOR 0
#define VERSION_MINOR 1

#define SERVER_PORT 65534

#define MAX_CLIENTS 500

int main(int argc, char **argv)
{
	printf("DataBaser Server V%d.%d\n",VERSION_MAJOR,VERSION_MINOR);
	
	printf("Enabling socket ...\n");
	int serverSocket;
	setupSocket(&serverSocket);
	
	printf("Starting client handling ...\n");
	clientsLoop(serverSocket);
	
	return 0;
}

int addToClientList(int socket, int * clientSockets)
{
	//add new socket to array of sockets
	for(int i = 0; i < MAX_CLIENTS; i++) 
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

int removeFromClientList(int socket, int * clientSockets)
{
	//add new socket to array of sockets
	for(int i = 0; i < MAX_CLIENTS; i++) 
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
int addSocketsToSelector(int serverSocket, int * clientSockets, fd_set * selector)
{
	//clear the socket set
	FD_ZERO(selector);
	//add master socket to set
	FD_SET(serverSocket, selector);
	int max_sd = serverSocket;
	//add child sockets to set
	for (int i = 0 ; i < MAX_CLIENTS ; i++) 
	{
		if(clientSockets[i] > 0) //if valid socket descriptor then add to read list
		{
			FD_SET(clientSockets[i], selector);			
		}
		
		if(clientSockets[i] > max_sd) //highest file descriptor number, need it for the select function
		{
			max_sd = clientSockets[i];			
		}
	}
	
	return max_sd;
}

void acceptClient(int serverSocket, int * clientSockets)
{
	struct sockaddr_in address;
	int addrlen;
	int newSocket = accept(serverSocket, (struct sockaddr *)&address, (socklen_t*)&addrlen);
	if(newSocket < 0)
	{
		printf("ERROR on accept\n");
		return;
	}
	
	if(addToClientList(newSocket, clientSockets) < 0)
	{
		printf("SERVER FULL\n");
		close(newSocket);
	}
}

int answerToClient(int clientSocket)
{
	char buffer[1024];
	int bufferLength = read(clientSocket , buffer, 1024);
	printf("read %dB\n",bufferLength);
	return bufferLength;
}

void clientsLoop(int serverSocket)
{
	int clientSockets[MAX_CLIENTS];
	memset(clientSockets,0,sizeof(int)*MAX_CLIENTS);
	
	fd_set selector;
	while(1)
	{
		int max_sd = addSocketsToSelector(serverSocket,clientSockets, &selector);
		
		//wait for an activity on one of the sockets , timeout is NULL , so wait indefinitely
        int activity = select( max_sd + 1 , &selector , NULL , NULL , NULL);
        if(activity < 0)
        {
            printf("ERROR on select\n");
        }
		
		  
        //If something happened on the master socket , then its an incoming connection
        if(FD_ISSET(serverSocket, &selector)) 
        {
			acceptClient(serverSocket,clientSockets);
        }
		else
		{
			//else its some IO operation on some other socket :)
			for (int i = 0; i < MAX_CLIENTS; i++) 
			{				  
				if(FD_ISSET(clientSockets[i] , &selector)) 
				{
					if(answerToClient(clientSockets[i]) == 0)
					{ // disconnected
						removeFromClientList(clientSockets[i],clientSockets);
					}
				}
			}
		}			

	}
}

bool setupSocket(int * serverSocket)
{
	struct sockaddr_in serverAddr;

	*serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (*serverSocket < 0) 
	{
		printf("ERROR opening socket\n");
		return true;
	}

	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = INADDR_ANY;
	serverAddr.sin_port = htons(SERVER_PORT);

	if (bind(*serverSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) < 0)
	{
		printf("ERROR Couldn't bind port !\nIs a server already running ?\n");
		return true;
	}
	
	if(listen(*serverSocket,3) < 0)
	{
		printf("ERROR while setting to listening mode\n");
		return true;
	}
	

	return false;
}