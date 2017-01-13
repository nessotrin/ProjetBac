#include "ConnectionHandler.h"

#include <netinet/in.h>
#include <cstdio>
#include <cstring>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>


bool ConnectionHandler::connectToIP(char * ip, int port)
{
	printf("Connecting to \"%s\" ...\n",ip);
    struct sockaddr_in serverAddr;
    struct hostent *server;

    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket < 0)
	{
		printf("ERROR opening socket !");
		return true;
	}
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr(ip);
    serverAddr.sin_port = htons(port);
    if (connect(clientSocket,(struct sockaddr *) &serverAddr,sizeof(serverAddr)) < 0)
	{
		printf("FAILED TO CONNECT !\n");
		return true;
	}
	
	printf("Sucessfully connected !\n");
	
    return false;
}


bool ConnectionHandler::doLogin(ModuleInfo info)
{
	char buffer[64]; 
	memcpy(buffer,"<3COOKIE",8);
	buffer[8] = info.type;
	buffer[9] = info.versionMajor;
	buffer[10] = info.versionMinor;
	buffer[11] = info.versionPatch;
	buffer[12] = info.isDebug;
	
	
	write(clientSocket,buffer,64);
	
	printf("Loggin'ed ! \n");
	return false;
}