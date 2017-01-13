#ifndef _SERVER_H_
#define _SERVER_H_

#include <fcntl.h>

class Server
{
public:
	Server(int newMaxClients, int newPort);

	bool setup();
	void work();
	
private:
	int port;
	int maxClients;
	int serverSocket;
	int * clientSockets;
	fd_set selector;
	
	int addToClientList(int socket);
	int removeFromClientList(int socket);

	int addSocketsToSelector();

	void acceptClient();
	int answerToClient(int clientSocket);
};

#endif // _SERVER_H_
