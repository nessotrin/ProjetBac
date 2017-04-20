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
	
	if(strlen(request) >= strlen("RecupPoidsUnitaireMedoc") && memcmp(request, "RecupPoidsUnitaireMedoc", strlen("RecupPoidsUnitaireMedoc")) == 0)
	{
		sendMedUnitWeigth(client, RequestHelper::getOneIntArg(request,strlen("RecupPoidsUnitaireMedoc")));
	}
	else if(strlen(request) >= strlen("RecupImageMedoc") && memcmp(request, "RecupImageMedoc", strlen("RecupImageMedoc")) == 0)
	{
		sendMedImg(client, RequestHelper::getOneIntArg(request,15));
	}
	else if(strlen(request) >= strlen("RecupNomMedoc") && memcmp(request, "RecupNomMedoc", strlen("RecupNomMedoc")) == 0)
	{
		sendMedName(client, RequestHelper::getOneIntArg(request,strlen("RecupNomMedoc")));
	}
	else if(strlen(request) >= strlen("RecupNombreMedoc") && memcmp(request, "RecupNombreMedoc", strlen("RecupNombreMedoc")) == 0)
	{
		sendMedCount(client, RequestHelper::getOneIntArg(request,strlen("RecupNombreMedoc")));
	}
	else if(strlen(request) >= 21 && memcmp(request, "RecupTailleListeMedoc", strlen("RecupTailleListeMedoc")) == 0)
	{
		sendMedListSize(client);
	}
	else if(strlen(request) >= 12 && memcmp(request, "RecupIdMedoc", strlen("RecupIdMedoc")) == 0)
	{
		sendMedId(client, RequestHelper::getOneIntArg(request,strlen("RecupIdMedoc")));
	}	
	else
	{
		Logger::log("Unknow request !!!\n");
		/* Échec */
	}
}