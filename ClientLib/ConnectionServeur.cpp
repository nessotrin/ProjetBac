#include "ConnectionServeur.h"

#include "ModuleInfo.h"
#include "IOHelper.h"

#include <cstdio>

ConnectionHandler ConnectionServeur::connectionHandler;

bool ConnectionServeur::initialisation(char * ip, int newType, int newVersionMajor, int newVersionMinor, int newVersionPatch, bool newIsDebug)
{
	printf("Init sur \"%s\"\n",ip);
	
	ModuleInfo info;
	info.type = newType;
	info.versionMajor = newVersionMajor;
	info.versionMinor = newVersionMinor;
	info.versionPatch = newVersionPatch;
	info.isDebug = newIsDebug;

	if(connectionHandler.connectToIP(ip,PORT))
	{
		printf("Failed to connect to given IP, fallback to localhost\n");
		if(connectionHandler.connectToIP("127.0.0.1",PORT))
		{
			printf("CRITICAL Failed to connect the server !\n");
			return true;
		}
	}

	connectionHandler.doLogin(info);

	return false;
}


bool ConnectionServeur::envoyer(char * message)
{
	return IOHelper::sendRequest(connectionHandler.getSocket(),message);
}

char * ConnectionServeur::recevoir()
{
	return IOHelper::getRequest(connectionHandler.getSocket());
}

void ConnectionServeur::fermer()
{
	connectionHandler.disconnect();
}