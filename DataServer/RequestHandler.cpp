#include "RequestHandler.h"

#include <stdio.h>

RequestHandler::RequestHandler(LoginHandler * newLoginHandler)
{
	loginHandler = newLoginHandler;
}


void RequestHandler::handleRequest(unsigned char * buffer, int length)
{
	buffer[length] = 0;
	printf("Received \"%s\"\n",buffer);
}
