#include "HumanRequest.h"

#include "IOHelper.h"

#include "Logger.h"

#include "RequestHelper.h"

#include <cstdio>
#include <cstring>

HumanRequest::HumanRequest(HumanHandler * newHumanHandler, RequestHandler * requestHandler)
{
	humanHandler = newHumanHandler;
	
	requestHandler->addRequestEntry("RecupImageHumain",this);
	requestHandler->addRequestEntry("RecupNomHumain",this);
	requestHandler->addRequestEntry("RecupTailleListeHumain",this);

	requestHandler->addRequestEntry("RecupListeAutoriseeHumain",this);
	
}


/***
Envoie le nombre de médicament du numéro donné
***/


void HumanRequest::sendHumanName(Client * client, int id)
{
	Logger::log("Human name asked for %d... \n", InfoLog, id);

	/* Création du buffer de communication */
	char buffer[1024];


	/* Récupération du médicament demandé */
	Human * selectedHuman = humanHandler->getHuman(id);
	
	
	/* Envoi du nom (comme défini par le protocol) */
	sprintf(buffer,"%s\n",selectedHuman->getName());
	
	
	/* Envoi du nom (comme défini par le protocol) */
	if(IOHelper::sendRequest(client->getSocket(), buffer)) 
	{
		/* Abandon */
		return;
	}

}


void HumanRequest::sendHumanImg(Client * client, int id)
{
	Logger::log("Human img asked for %d... \n", InfoLog, id);

	/* Création du buffer de communication */
	char buffer[1024];
	
	/* Récupération du médicament demandé */
	Human * selectedHuman = humanHandler->getHuman(id);
	

	/* Envoi du nom (comme défini par le protocol) */
	sprintf(buffer,"%s\n",selectedHuman->getImg());

	
	/* Envoi du nom (comme défini par le protocol) */
	if(IOHelper::sendRequest(client->getSocket(), buffer)) 
	{
		/* Abandon */
		return;
	}
}

void HumanRequest::sendHumanListSize(Client * client)
{
	Logger::log("Human list size asked ... \n", InfoLog);
	

	/* Création du buffer de communication */
	char buffer[1024];

	/* Envoi du nom (comme défini par le protocol) */
	sprintf(buffer,"Nombre%d\n",  humanHandler->getHumanCount());

	/* Envoi du nom (comme défini par le protocol) */
	if(IOHelper::sendRequest(client->getSocket(),buffer)) 
	{
		/* Abandon */
		return;
	}

}


void HumanRequest::sendHumanAuthorizedIDs(Client * client, int id)
{
	Logger::log("Authorized Medecines asked for human %d... \n", InfoLog, id);

	/* Récupération du médicament demandé */
	Human * selectedHuman = humanHandler->getHuman(id);

	/*TODO*/
	Logger::log("TODO!!\n",ErrorLog);

	
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
	
	

	if(strlen(request) >= strlen("RecupImageHumain") && memcmp(request, "RecupImageHumain", strlen("RecupImageHumain")) == 0)
	{
		sendHumanImg(client, RequestHelper::getOneIntArg(request,strlen("RecupImageHumain")));
	}


	else if(strlen(request) >= strlen("RecupNomHumain") && memcmp(request, "RecupNomHumain", strlen("RecupNomHumain")) == 0)
	{
		sendHumanName(client, RequestHelper::getOneIntArg(request,strlen("RecupNomHumain")));
	}


	else if(strlen(request) >= strlen("RecupTailleListeHumain") && memcmp(request, "RecupTailleListeHumain", strlen("RecupTailleListeHumain")) == 0)
	{
		sendHumanListSize(client);
	}

	else if(strlen(request) >= strlen("RecupListeAutoriseeHumain") && memcmp(request, "RecupListeAutoriseeHumain", strlen("RecupListeAutoriseeHumain")) == 0)
	{
		sendHumanAuthorizedIDs(client, RequestHelper::getOneIntArg(request,strlen("RecupListeAutoriseeHumain")));
	}
	else
	{
		Logger::log("Unknow request !!!\n",WarningLog);
		/* Échec */
	}
	
}
