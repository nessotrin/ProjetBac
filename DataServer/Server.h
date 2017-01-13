#ifndef _SERVER_H_
#define _SERVER_H_

#include "RequestHandler.h"
 
#include <fcntl.h>

class Server
{
public:
	Server(int newMaxClients, int newPort, RequestHandler * newRequestHandler);

	bool setup();
	void work();
	
private:
	RequestHandler * requestHandler;
	int port;
	int maxClients;
	int serverSocket;
	int * clientSockets;
	fd_set selector;
	
	int addToClientList(int socket);
	int removeFromClientList(int socket);

	int addSocketsToSelector();

	void acceptClient();
	void handleClients();
	int answerToClient(int clientSocket);
};

#endif // _SERVER_H_
