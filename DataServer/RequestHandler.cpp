#include "RequestHandler.h"

#include <stdio.h>

RequestHandler::RequestHandler(LoginHandler * newLoginHandler)
{
	loginHandler = newLoginHandler;
}


int RequestHandler::handleRequest(Client * client)
{
//	printf("Received \"%s\"\n",buffer);
	unsigned char buffer[1024];
	
	int length = client->receiveData(buffer,1024);
	if(length > 0)
	{
		if(length < 16)
		{
			printf("BROKEN REQUEST !\n");
			return length;
		}
		if(memcmp("GETMEDLISTCOMPLE",buffer,16) == 0)
		{
			
		}
	}
	
	
	
	return length;
}