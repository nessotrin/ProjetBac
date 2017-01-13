#include "Client.h"

#include <unistd.h>

Client::Client(int newSocket)
{
	socket = newSocket;
}

int Client::getSocket()
{
	return socket;
}


void Client::setType(int newType)
{
	type = newType;
}
int Client::getType()
{
	return type;
}

void Client::setDebug(bool newDebug)
{
	debug = newDebug;
}
bool Client::getDebug()
{
	return debug;
}


int Client::sendData(unsigned char * data, int size)
{
	return write(socket, data, size);
}

int Client::receiveData(unsigned char * data, int maxSize)
{
	return read(socket, data, maxSize);
}