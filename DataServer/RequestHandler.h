#ifndef _REQUEST_HANDLER_H_
#define _REQUEST_HANDLER_H_

#include "LoginHandler.h"

#include "MedRequest.h"

class RequestHandler
{
public:
	RequestHandler(LoginHandler * newLoginHandler, MedRequest * newMedRequest);
	
	bool handleRequest(Client * client);
private:

	LoginHandler * loginHandler;
	MedRequest * medRequest;
};

#endif // _REQUEST_HANDLER_H_
