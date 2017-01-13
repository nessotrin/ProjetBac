#ifndef _LOGIN_HANDLER_H_
#define _LOGIN_HANDLER_H_

#include "LoginHandler.h"
#include "Client.h"

#include <cstring>


class LoginHandler
{
public:
	LoginHandler();

	int iterateOnSockets(int * socketToUse);
	int addNewClient(int socket);
	int disconnect(int socket);
	
private:
	void removeFromList(int id);

	Client ** clientList ;
	int clientCount;
	
	int iteratorCounter;
};

#endif // _LOGIN_HANDLER_H_
