#ifndef _LOGIN_HANDLER_H_
#define _LOGIN_HANDLER_H_

#include "LoginHandler.h"
#include "Client.h"

#include <cstring>

#include "LoginProtocol.h"

/***
Class handler qui gère et stock les clients
***/

class LoginHandler
{
public:
	LoginHandler();

	bool iterateOnSockets(int * socketToUse);
	int getClientCount();
	Client * getClient(int id);
	bool addNewClient(int socket);
	void disconnect(int socket);
	
private:
	
	LoginProtocol loginProtocol;

	void removeFromList(int id);

	Client ** clientList;
	int clientCount;
	
	int iteratorCounter;
};

#endif // _LOGIN_HANDLER_H_
