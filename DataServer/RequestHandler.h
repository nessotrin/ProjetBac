#ifndef _REQUEST_HANDLER_H_
#define _REQUEST_HANDLER_H_

#include "LoginHandler.h"

class RequestHandler
{
public:
	RequestHandler(LoginHandler * newLoginHandler);
	
	void handleRequest(unsigned char * buffer, int length);
private:

	LoginHandler * loginHandler;
};

#endif // _REQUEST_HANDLER_H_
