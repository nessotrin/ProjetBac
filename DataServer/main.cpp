#include "Server.h"
#include "RequestHandler.h"
#include "RequestMaker.h"


#include <stdio.h>


#define VERSION_MAJOR 0
#define VERSION_MINOR 1

#define SERVER_PORT 65534

int main(int argc, char **argv)
{
	printf("DataBaser Server V%d.%d\n",VERSION_MAJOR,VERSION_MINOR);
	
	printf("Initializing med handler ...\n");
	MedHandler medHandler; 
	
	LoginHandler loginHandler;
	
	RequestHandler requestHandler(&loginHandler,&medHandler);
	Server server(SERVER_PORT, &loginHandler, &requestHandler);
	RequestMaker requestMaker(&loginHandler);
	

	printf("Setuping database ...\n");

	
	printf("Setup'ing server ...\n");

	if(server.setup())
	{
		return 1;
	}
	
	printf("Starting client handling ...\n");
	server.work();
	
	
	return 0;
}