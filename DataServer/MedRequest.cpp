#include "MedRequest.h"

#include "IOHelper.h"

#include "Logger.h"

#include "RequestHelper.h"


#include <cstdio>
#include <cstring>

MedRequest::MedRequest(MedHandler * newMedHandler)
{
	medHandler = newMedHandler;
}


/***
Envoie le nom de l'img du médicament au numéro donné
***/
void MedRequest::sendMedUnitWeigth(Client * client, int id)
{
	/* Création du buffer de communication */
	char buffer[1024];

	/* Récupération du médicament demandé */
	Med * selectedMed = medHandler->getMed(id);
	
	/* Envoi du nom (comme défini par le protocol) */
	sprintf(buffer,"PoidUnitaire%d\n",selectedMed->getUnitWeigth());
	if(IOHelper::sendRequest(client->getSocket(),buffer)) 
	{
		/* Abandon */
		return;
	}

}


/***
Envoie la liste complète des médicaments et leurs info
***/
void MedRequest::sendMedImg(Client * client, int id)
{
	/* Création du buffer de communication */
	char buffer[1024];
	
	/* Création et envoie d'un message donnant le nombre total de médicaments */
	sprintf(buffer, "%s\n",medHandler->getMed(id)->getImg());
	if(IOHelper::sendRequest(client->getSocket(),buffer)) /* Vérification échec */
	{
		/* Abandon */
		return; 
	}
	
	Logger::log("Med img sent !\n");
}


/***
Envoie le nom de l'img du médicament au numéro donné
***/
void MedRequest::sendMedName(Client * client, int id)
{
	printf("Send med name\n");
	
	/* Création du buffer de communication */
	char buffer[1024];

	/* Récupération du médicament demandé */
	Med * selectedMed = medHandler->getMed(id);
	
	/* Envoi du nom (comme défini par le protocol) */
	sprintf(buffer,"%s\n",selectedMed->getName());
	if(IOHelper::sendRequest(client->getSocket(),buffer)) 
	{
		/* Abandon */
		return;
	}

}

/***
Envoie le nom de l'img du médicament au numéro donné
***/
void MedRequest::sendMedCount(Client * client, int id)
{
	/* Création du buffer de communication */
	char buffer[1024];

	/* Récupération du médicament demandé */
	Med * selectedMed = medHandler->getMed(id);
	
	/* Envoi du nom (comme défini par le protocol) */
	sprintf(buffer,"Nombre%d\n",selectedMed->getCurrentCount());
	if(IOHelper::sendRequest(client->getSocket(),buffer)) 
	{
		/* Abandon */
		return;
	}

}


/***
Envoie le nombre de médicament du numéro donné
***/
void MedRequest::sendMedListSize(Client * client)
{
	/* Création du buffer de communication */
	char buffer[1024];

	/* Envoi du nom (comme défini par le protocol) */
	sprintf(buffer,"Nombre%d\n",medHandler->getMedCount());
	if(IOHelper::sendRequest(client->getSocket(),buffer)) 
	{
		/* Abandon */
		return;
	}

}


/***
Envoie le nombre de médicament du numéro donné
***/
void MedRequest::sendMedId(Client * client, int id)
{
	Logger::log("Count asked on med %d... \n", id);
	/* Création du buffer de communication */
	char buffer[1024];

	/* Récupération du médicament demandé */
	Med * selectedMed = medHandler->getMed(id);
	
	/* Envoi du nom (comme défini par le protocol) */
//	sprintf(buffer,"Id%d\n",selectedMed->getMedId); TODO
	if(IOHelper::sendRequest(client->getSocket(),buffer)) 
	{
		/* Abandon */
		return;
	}

}



void MedRequest::handleRequest(char * request, Client * client)
{
		/* Comparaisons */
	
	printf("handleRequest with MEDHANDLER\n");
	
	if(strlen(request) >= 23 && memcmp(request, "RecupPoidsUnitaireMedoc", 23) == 0)
	{
		sendMedUnitWeigth(client, RequestHelper::getOneIntArg(request,23));
	}
	else if(strlen(request) >= 15 && memcmp(request, "RecupImageMedoc", 15) == 0)
	{
		sendMedImg(client, RequestHelper::getOneIntArg(request,15));
	}
	else if(strlen(request) >= 13 && memcmp(request, "RecupNomMedoc", 13) == 0)
	{
		sendMedName(client, RequestHelper::getOneIntArg(request,13));
	}
	else if(strlen(request) >= 16 && memcmp(request, "RecupNombreMedoc", 16) == 0)
	{
		sendMedCount(client, RequestHelper::getOneIntArg(request,16));
	}
	else if(strlen(request) >= 21 && memcmp(request, "RecupTailleListeMedoc", 21) == 0)
	{
		sendMedListSize(client);
	}
	else if(strlen(request) >= 12 && memcmp(request, "RecupIdMedoc", 12) == 0)
	{
		sendMedId(client, RequestHelper::getOneIntArg(request,12));
	}	
	else
	{
		Logger::log("Unknow request !!!\n");
		/* Échec */
	}
}