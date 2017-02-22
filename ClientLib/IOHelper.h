#ifndef _IO_HELPER_H_
#define _IO_HELPER_H_

/***
Class helper qui simplifie les envoie et receptions de messages standards avec des fonctions
***/

class IOHelper
{
	
public:
	static char * sendRequestAndGetRequest(int clientSocket, char * requestBuffer);
	static char * getRequest(int clientSocket);
	static bool sendRequest(int clientSocket, char * requestBuffer);
};

#endif // _IO_HELPER_H_
