#ifndef _CONNECTION_HANDLER_H_
#define _CONNECTION_HANDLER_H_

#include "ModuleInfo.h"

/***
Définition de la class ConnectionHandler
***/
class ConnectionHandler
{
public:
	bool connectToIP(char * ip, int port);
	bool doLogin(ModuleInfo info);
	void disconnect();
	int getSocket();

private:
	int clientSocket;
};

#endif // _CONNECTION_HANDLER_H_
