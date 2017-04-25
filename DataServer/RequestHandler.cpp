#include "RequestHandler.h"
#include "IOHelper.h"
#include "Logger.h"
#include "RequestMap.h"


#include <stdio.h>

RequestHandler::RequestHandler(MedRequest * newMedRequest, HumanRequest * newHumanRequest, LogRequest * newLogRequest)
{
	medRequest = newMedRequest;
	humanRequest = newHumanRequest;
	logRequest = newLogRequest;
}


/***
Reçoit une requête directement du client, l'analyse et le distribue au bon handler
***/
bool RequestHandler::triageRequest(Client * client)
{
	Logger::log("Receiving request ...\n",InfoLog);
	
	/* Reçoit la requête */
	char * request = IOHelper::getRequest(client->getSocket());
	if(request == NULL) /* Vérification d'échec */
	{
		Logger::log("Bad request ...\n",WarningLog);
		/* Abandon */
		return true;
	}
	
	Logger::log("Analyzing request \"%s\"...\n",InfoLog,request);
	
	if(RequestMap::getBroadcastTo(request) != -1)
	{
		//TODO: write broadcast
		Logger::log("BROADCAST SYSTEM: TODO !!!!!",ErrorLog);
	}
	
	switch(RequestMap::getDesignatedRequestHandler(request))
	{
		case MED_REQUEST:
			medRequest->handleRequest(request, client);
		break;
		case HUMAN_REQUEST:
			humanRequest->handleRequest(request, client);
		break;
		case LOG_REQUEST:
			logRequest->handleRequest(request, client);
		break;
		default:
			printf("NO HANDLER FOR REQUEST ! %d\n",RequestMap::getDesignatedRequestHandler(request));
	}
	
	
	
	
	/* Réussite*/
	return false;
}