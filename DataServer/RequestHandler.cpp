#include "RequestHandler.h"
#include "IOHelper.h"


#include <stdio.h>

RequestHandler::RequestHandler(LoginHandler * newLoginHandler, MedHandler * newMedHandler)
{
	loginHandler = newLoginHandler;
	medHandler = newMedHandler;
}


bool RequestHandler::handleRequest(Client * client)
{
	char * request = IOHelper::getRequest(client->getSocket());
	if(request == NULL)
	{
		printf("Bad request ...\n");
		return true;
	}
	
	if(strlen(request) >= 16 && memcmp(request, "ListerMedicaments", 17) == 0)
	{
		printf("Liste des médicaments demandée\n");
	}
	
	
	return false;
}