#ifndef _MED_REQUEST_H_
#define _MED_REQUEST_H_

#include "MedHandler.h"

#include "Client.h"

#include "RequestCallbackable.h"

#include "RequestHandler.h"

/***
Class request handler qui répond à toutes les requêtes sur les médicaments
***/
class MedRequest : public RequestCallbackable
{
public:
	MedRequest(MedHandler * newMedHandler, RequestHandler * requestHandler);
	void sendMedUnitWeigth(Client * client, int id);
	void sendMedImg(Client * client, int id);
	void sendMedName(Client * client, int id);
	void sendMedCount(Client * client, int id);
	void sendMedListSize(Client * client);
	void sendMedId(Client * client, int id);
	void handleRequest(char * request, Client * client);

private:
	MedHandler * medHandler;
};

#endif // _MED_REQUEST_H_
