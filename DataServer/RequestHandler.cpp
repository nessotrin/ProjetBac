#include "RequestHandler.h"
#include "IOHelper.h"
#include "Logger.h"



#include <stdio.h>

RequestHandler::RequestHandler()
{

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

	bool wasFound = false;

	for(int i = 0 ; i < requestList.getCount() ; i++)
	{
		if(strlen(request) >= strlen(requestList.get(i)->name) && memcmp(request,requestList.get(i)->name, strlen(requestList.get(i)->name)) == 0)
		{
			requestList.get(i)->callbackable->handleRequest(request,client);
			wasFound = true;
		}
	}
	
	if(!wasFound)
	{
		Logger::log("REQUEST UNKOWN !\n",ErrorLog);
	}
/*
	
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
		case BROADCAST_REQUEST:
			logRequest->handleRequest(request, client);
		break;
		default:
			printf("NO HANDLER FOR REQUEST ! %d\n",RequestMap::getDesignatedRequestHandler(request));
	}
	
	
	*/
	
	/* Réussite*/
	return false;
}

void RequestHandler::addRequestEntry(char * name, RequestCallbackable * callbackable)
{
	requestList.add(new RequestHandlerEntry(name,callbackable));
}