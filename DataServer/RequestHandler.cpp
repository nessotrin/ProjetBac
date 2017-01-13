#include "RequestHandler.h"

#include <stdio.h>

void RequestHandler::handleRequest(unsigned char * buffer, int length)
{
	buffer[length] = 0;
	printf("Received \"%s\"\n",buffer);
}
