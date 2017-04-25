#ifndef _LOG_REQUEST_H_
#define _LOG_REQUEST_H_

#include "Client.h"

class LogRequest
{
public:
	void handleRequest(char * request, Client * client);
};




#endif // _LOG_REQUEST_H_
