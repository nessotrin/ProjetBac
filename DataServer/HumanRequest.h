#ifndef _HUMANREQUEST_H_
#define _HUMANREQUEST_H_

#include "HumanHandler.h"

#include "Client.h"

#include "RequestHandler.h"

#include "RequestCallbackable.h"
/***
Class request handler qui répond à toutes les requêtes sur les humains
***/
class HumanRequest : public RequestCallbackable
{
public:
	HumanRequest(HumanHandler * newHumanHandler, RequestHandler * requestHandler);

	void handleRequest(char * request, Client * client);

private:

	void sendHumanName(Client * client, int id);
	void sendHumanImg(Client * client, int id);
	void sendHumanListSize(Client * client);
	void sendHumanAuthorizedIDs(Client * client, int id);


	HumanHandler * humanHandler;
};

#endif // _HUMANREQUEST_H_
