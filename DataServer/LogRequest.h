#ifndef _LOG_REQUEST_H_
#define _LOG_REQUEST_H_

#include "Client.h"

#include "RequestCallbackable.h"

#include "RequestHandler.h"

class LogRequest : public RequestCallbackable
{
public:

	LogRequest(RequestHandler * requestHandler);

	void handleRequest(char * request, Client * client);
};




#endif // _LOG_REQUEST_H_
