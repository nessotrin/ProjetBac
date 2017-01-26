#include "RequestHandler.h"
#include "IOHelper.h"


#include <stdio.h>

RequestHandler::RequestHandler(LoginHandler * newLoginHandler, MedRequest * newMedRequest)
{
	loginHandler = newLoginHandler;
	medRequest = newMedRequest;
}

/***
Reçoit une requête directement du client, l'analyse et le distribue au bon handler
***/
bool RequestHandler::handleRequest(Client * client)
{
	/* Reçoit la requête */
	char * request = IOHelper::getRequest(client->getSocket());
	if(request == NULL) /* Vérification d'échec */
	{
		printf("Bad request ...\n");
		/* Abandon */
		return true;
	}
	
	/* Comparaisons */
	
	if(strlen(request) >= 16 && memcmp(request, "ListerMedicaments", 17) == 0)
	{
		medRequest->sendMedList(client);
	}
	else if(strlen(request) >= 16 && memcmp(request, "InfoMedicament", 14) == 0)
	{
		int id;
		sscanf(reponse,"InfoMedicament%d\n",&id);
		medRequest->sendMedInfo(client,id);
	}
	else
	{
		printf("Unknow request !!!\n");
		/* Échec */
		return true;
	}
	
	/* Réussite*/
	return false;
}