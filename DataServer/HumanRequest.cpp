#include "HumanRequest.h"

#include "IOHelper.h"

#include "Logger.h"

#include "RequestHelper.h"

#include <cstdio>
#include <cstring>

HumanRequest::HumanRequest(HumanHandler * newHumanHandler)
{
	humanHandler = newHumanHandler;
}

/***
Envoie le nombre de médicament du numéro donné
***/



void HumanRequest::sendHumanAuthorizedIDs(Client * client, int id)
{
	Logger::log("Authorized Medecines asked for human %d... \n", id);

	/* Récupération du médicament demandé */
	Human * selectedHuman = humanHandler->getHuman(id);

	/*TODO*/
	Logger::log("TODO!!\n");

	
	/* Envoi du nom (comme défini par le protocol) */
	if(IOHelper::sendRequest(client->getSocket(),selectedHuman->getName())) 
	{
		/* Abandon */
		return;
	}

}



void HumanRequest::sendHumanName(Client * client, int id)
{
	Logger::log("Human name asked for %d... \n", id);

	/* Récupération du médicament demandé */
	Human * selectedHuman = humanHandler->getHuman(id);
	
	/* Envoi du nom (comme défini par le protocol) */
	if(IOHelper::sendRequest(client->getSocket(),selectedHuman->getName())) 
	{
		/* Abandon */
		return;
	}

}



void HumanRequest::handleRequest(char * request, Client * client)
{
		/* Comparaisons */
	
	printf("handleRequest with HUMANREQUEST\n");
		
	if(strlen(request) >= 15 && memcmp(request, "RecupNomMedecin", 15) == 0)
	{
		sendHumanName(client, RequestHelper::getOneIntArg(request,15));
	}
	else if(strlen(request) >= 23 && memcmp(request, "RecupIdAutorisesMedecin", 23) == 0)
	{
		sendHumanAuthorizedIDs(client, RequestHelper::getOneIntArg(request,23));
	}
	else
	{
		Logger::log("Unknow request !!!\n");
		/* Échec */
	}
}
