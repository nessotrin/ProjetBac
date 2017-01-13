#include "Client.h"

Client::Client(int newSocket)
{
	socket = newSocket;
}

int Client::getSocket()
{
	return socket;
}
