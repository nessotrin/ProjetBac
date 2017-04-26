#ifndef _REQUEST_HANDLER_H_
#define _REQUEST_HANDLER_H_

#include "LoginHandler.h"

#include "RequestCallbackable.h"

#include "ServerHelper.h"

class RequestHandlerEntry
{
public:
	RequestHandlerEntry(char * newName, RequestCallbackable * newCallbackable)
	{
		name = newName;
		callbackable = newCallbackable;
	}
	
	
	char * name;
	RequestCallbackable * callbackable;
};


/***
Class request handler qui gère toutes les requêtes qui arrivent et les redistribues handlers respectifs
***/
class RequestHandler
{
public:
	RequestHandler();
	
	bool triageRequest(Client * client);
	
	void addRequestEntry(char * name, RequestCallbackable * callbackable);
	
private:

	List<RequestHandlerEntry> requestList;

};

#endif // _REQUEST_HANDLER_H_
