#include "LoginProtocol.h"

#include "TextResolver.h"

#include <cstring>
#include <cstdio>

bool LoginProtocol::doLogin(Client * client)
{
	unsigned char buffer[64];
	client->receiveData(buffer,64);
	
	if(memcmp(buffer,"<3COOKIE",8) != 0)
	{
		printf("Client has the wrong magic !\n");
		return true;
	}
	printf("Info module:\nType %s\nVersion %d.%d.%d\nDebug: %s\n",TextResolver::typeToName(buffer[8]),buffer[9],buffer[10],buffer[11],TextResolver::boolToFrench(buffer[12]));
	
	client->setType(buffer[8]);
	client->setDebug(buffer[12]);
	
	return 0;
}
