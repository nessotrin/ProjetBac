#ifndef _REQUEST_CALLBACKABLE_H_
#define _REQUEST_CALLBACKABLE_H_

#include "Client.h"

class RequestCallbackable
{
public:

	virtual void handleRequest(char * request, Client * client) = 0;

};

#endif // _REQUEST_CALLBACKABLE_H_
