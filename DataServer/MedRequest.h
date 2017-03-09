#ifndef _MED_REQUEST_H_
#define _MED_REQUEST_H_

#include "MedHandler.h"

#include "Client.h"

/***
Class request handler qui répond à toutes les requêtes sur les médicaments
***/
class MedRequest
{
public:
	MedRequest(MedHandler * newMedHandler);
	void sendMedList(Client * client);
	void sendMedInfo(Client * client, int id);
	void sendMedCount(Client * client, int id);
	void sendMedImg(Client * client, int id);
	void handleRequest(char * request, Client * client);

private:
	MedHandler * medHandler;
};

#endif // _MED_REQUEST_H_
