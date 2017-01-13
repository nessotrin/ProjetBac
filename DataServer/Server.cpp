#include "Server.h"


#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <netinet/in.h>
#include <unistd.h>



Server::Server(int newMaxClients, int newPort, LoginHandler * newLoginHandler, RequestHandler * newRequestHandler)
{
	maxClients = newMaxClients;
	port = newPort;
	requestHandler = newRequestHandler;
	loginHandler = newLoginHandler;
}

int Server::addSocketsToSelector()
{
	//clear the socket set
	FD_ZERO(&selector);
	//add master socket to set
	FD_SET(serverSocket, &selector);
	int max_sd = serverSocket;
	//add child sockets to set
	int socket;
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

void Server::acceptClient()
{
	printf("New client connecting ...\n");
	
	struct sockaddr_in address;
	int addrlen;
	int newSocket = accept(serverSocket, (struct sockaddr *)&address, (socklen_t*)&addrlen);
	if(newSocket < 0)
	{
		printf("ERROR on accept\n");
		return;
	}
	
	if(loginHandler->addNewClient(newSocket))
	{
		printf("SERVER FULL or CONNECTION FAILED\n");
		close(newSocket);
	}
	
	printf("Client fully connected !\n");
}

int Server::answerToClient(int clientSocket)
{
	unsigned char buffer[1024];
	int bufferLength = read(clientSocket , buffer, 1024);
	printf("read %dB\n",bufferLength);
	
	if(bufferLength > 0)
	{
		requestHandler->handleRequest(buffer,bufferLength);
	}
	
	
	return bufferLength;
}

void Server::handleClients()
{
	printf("Handling clients ...\n");
	int socket;
	while (loginHandler->iterateOnSockets(&socket)) 
	{
		printf("Checking socket ...\n");
		if(FD_ISSET(socket, &selector)) 
		{
			if(answerToClient(socket) == 0)
			{ // disconnected
				loginHandler->disconnect(socket);
			}
		}
		printf("Socket checked ...\n");
	}
}

void Server::work()
{
	while(1)
	{
		printf("Setting up selector ... \n");
		int max_sd = addSocketsToSelector();
		printf("Set'ed up ! \n");
		
		printf("Waiting for activity on sockets ...\n");
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
			handleClients();
		}			
		printf("Activity loop restarting ... \n");
	}
}

bool Server::setup()
{
	
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