#ifndef _IO_HELPER_H_
#define _IO_HELPER_H_

class IOHelper
{
public:
	static char * sendRequestAndGetRequest(int clientSocket, char * requestBuffer);
	static char * getRequest(int clientSocket);
	static bool sendRequest(int clientSocket, char * requestBuffer);
};

#endif // _IO_HELPER_H_
