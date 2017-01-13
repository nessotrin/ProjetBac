#ifndef _LOGIN_HANDLER_H_
#define _LOGIN_HANDLER_H_

#include "LoginHandler.h"
#include "Client.h"


class LoginHandler
{
public:
	int iterateOnSockets(int * socketToUse);
	int addNewClient(int socket);
	int disconnect(int socket);
	
private:
	void removeFromList(int id);

	Client ** clientList;
	int clientCount = 0;
	
	int iteratorCounter = 0;
};

#endif // _LOGIN_HANDLER_H_
