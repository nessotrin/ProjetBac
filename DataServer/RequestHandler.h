#ifndef _REQUEST_HANDLER_H_
#define _REQUEST_HANDLER_H_

#include "LoginHandler.h"

class RequestHandler
{
public:
	RequestHandler(LoginHandler * newLoginHandler);
	
	int handleRequest(Client * client);
private:

	LoginHandler * loginHandler;
};

#endif // _REQUEST_HANDLER_H_
