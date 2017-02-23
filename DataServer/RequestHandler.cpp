#include "RequestHandler.h"
#include "IOHelper.h"
#include "Logger.h"


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
	Logger::log("Receiving request ...\n");
	
	/* Reçoit la requête */
	char * request = IOHelper::getRequest(client->getSocket());
	if(request == NULL) /* Vérification d'échec */
	{
		Logger::log("Bad request ...\n");
		/* Abandon */
		return true;
	}
	
	Logger::log("Analyzing request ...\n");
	
	/* Comparaisons */
	
	if(strlen(request) >= 16 && memcmp(request, "ListerMedicaments", 17) == 0)
	{
		/* On envoie la liste des médicaments */
		medRequest->sendMedList(client);
	}
	else if(strlen(request) >= 13 && memcmp(request, "ImgMedicament", 13) == 0)
	{
		/* On récupère le numéro dans la requête*/
		int id;
		sscanf(request,"ImgMedicament%d\n",&id);
		
		/* On envoie l'image demandée*/
		medRequest->sendMedImg(client,id);
	}
	else if(strlen(request) >= 13 && memcmp(request, "NombreMedicament", 16) == 0)
	{
		/* On récupère le numéro dans la requête*/
		int id;
		sscanf(request,"NombreMedicament%d\n",&id);
		
		/* On envoie l'image demandée*/
		medRequest->sendMedCount(client,id);
	}
	else if(strlen(request) >= 15 && memcmp(request, "InfoMedicaments", 15) == 0)
	{
		/* On récupère le numéro dans la requête */		
		int id;
		sscanf(request,"InfoMedicaments<%d\n",&id);
		
		/* On envoie les info sur le médicament */
		medRequest->sendMedInfo(client,id);
	}
	else
	{
		Logger::log("Unknow request !!!\n");
		/* Échec */
		return true;
	}
	
	/* Réussite*/
	return false;
}