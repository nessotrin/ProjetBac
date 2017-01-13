#include "LoginProtocol.h"

#include "TextResolver.h"

#include <cstring>
#include <cstdio>

bool LoginProtocol::doLogin(Client * client)
{
	unsigned char buffer[64];
	
	int length = client->receiveData(buffer,64);
	
	if(length < 13)
	{
		printf("Client didn't send enough login data ! (%d/%d)\n",length,13);
		return true;
	}
	
	if(memcmp(buffer,"<3COOKIE",8) != 0)
	{
		printf("Client has the wrong magic !\n");
		printf("\"");
		for(int i = 0 ; i < 8 ; i++)
		{
			printf("%c");
		}
		printf("\"\n");
		return true;
	}
	printf("Info module:\nType %s\nVersion %d.%d.%d\nDebug: %s\n",TextResolver::typeToName(buffer[8]),buffer[9],buffer[10],buffer[11],TextResolver::boolToFrench(buffer[12]));
	
	client->setType(buffer[8]);
	client->setDebug(buffer[12]);
	
	return false;
}
