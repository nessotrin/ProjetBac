#include "Server.h"

#include <stdio.h>


#define VERSION_MAJOR 0
#define VERSION_MINOR 1

#define SERVER_PORT 65534

#define MAX_CLIENTS 20

int main(int argc, char **argv)
{
	printf("DataBaser Server V%d.%d\n",VERSION_MAJOR,VERSION_MINOR);
	
	printf("Setup'ing server ...\n");
	Server server(MAX_CLIENTS, SERVER_PORT);
	if(server.setup())
	{
		return 1;
	}
	
	printf("Starting client handling ...\n");
	server.work();
	
	
	return 0;
}