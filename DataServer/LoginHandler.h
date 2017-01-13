#ifndef _LOGIN_HANDLER_H_
#define _LOGIN_HANDLER_H_

#include "LoginHandler.h"
#include "Client.h"

#include <cstring>

#include "LoginProtocol.h"

class LoginHandler
{
public:
	LoginHandler();

	int iterateOnSockets(int * socketToUse);
	int iterateOnClients(Client ** clientToUse);
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
