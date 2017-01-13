#ifndef _REQUEST_HANDLER_H_
#define _REQUEST_HANDLER_H_

#include "LoginHandler.h"

#include "MedHandler.h"

class RequestHandler
{
public:
	RequestHandler(LoginHandler * newLoginHandler, MedHandler * newMedHandler);
	
	bool handleRequest(Client * client);
private:

	LoginHandler * loginHandler;
	MedHandler * medHandler;
};

#endif // _REQUEST_HANDLER_H_
