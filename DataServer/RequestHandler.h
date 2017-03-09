#ifndef _REQUEST_HANDLER_H_
#define _REQUEST_HANDLER_H_

#include "LoginHandler.h"

#include "MedRequest.h"

/***
Class request handler qui gère toutes les requêtes qui arrivent et les redistribues handlers respectifs
***/
class RequestHandler
{
public:
	RequestHandler(MedRequest * newMedRequest);
	
	bool triageRequest(Client * client);
private:

	LoginHandler * loginHandler;
	MedRequest * medRequest;
};

#endif // _REQUEST_HANDLER_H_
