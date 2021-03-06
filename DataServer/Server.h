#ifndef _SERVER_H_
#define _SERVER_H_

#include "RequestHandler.h"
#include "LoginHandler.h"
 
#include <fcntl.h>

/***
Class server qui gère le serveur
***/

class Server
{
public:
	Server(int newPort, LoginHandler * newLoginHandler, RequestHandler * newRequestHandler);

	bool setup();
	void work();
	
private:
	LoginHandler * loginHandler;
	RequestHandler * requestHandler;
	int port;
	int serverSocket;
	fd_set selector;
	
	int addToClientList(int socket);
	int removeFromClientList(int socket);

	int addSocketsToSelector();

	void acceptClient();
	void handleClients();
};

#endif // _SERVER_H_
