#ifndef _SERVER_H_
#define _SERVER_H_

#include <fcntl.h>

int addToClientList(int socket, int * clientSockets);
int removeFromClientList(int socket, int * clientSockets);
int addSocketsToSelector(int serverSocket, int * clientSockets, fd_set * selector);
void clientsLoop(int serverSocket);
void answerRequests();
bool setupSocket(int * serverSocket);
void acceptClient(int serverSocket, int * clientSockets);

#endif //_SERVER_H_