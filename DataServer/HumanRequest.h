#ifndef _HUMANREQUEST_H_
#define _HUMANREQUEST_H_

#include "HumanHandler.h"

#include "Client.h"

/***
Class request handler qui répond à toutes les requêtes sur les humains
***/
class HumanRequest
{
public:
	HumanRequest(HumanHandler * newHumanHandler);
	void sendHumanName(Client * client, int id);
	void sendHumanAuthorizedIDs(Client * client, int id);

	void handleRequest(char * request, Client * client);

private:
	HumanHandler * humanHandler;
};

#endif // _HUMANREQUEST_H_
