#include "MedRequest.h"

#include "IOHelper.h"

#include "Logger.h"


#include <cstdio>
#include <cstring>

MedRequest::MedRequest(MedHandler * newMedHandler)
{
	medHandler = newMedHandler;
}


/***
Envoie la liste complète des médicaments et leurs info
***/
void MedRequest::sendMedList(Client * client)
{
	Logger::log("Medlist asked ... \n");
	/* Création du buffer de communication */
	char buffer[1024];
	
	/* Création et envoie d'un message donnant le nombre total de médicaments */
	sprintf(buffer, "Nombre%d\n",medHandler->getMedCount());
	if(IOHelper::sendRequest(client->getSocket(),buffer)) /* Vérification échec */
	{
		/* Abandon */
		return; 
	}
	
	Logger::log("Medcount sent !\n");
	
	Med * med;
	/* Boucle sur les médicaments */
	while(medHandler->iterateOnMeds(&med))
	{
		/* Création et envoie d'un message contenant le nom du médicament */
		sprintf(buffer, "%s\n",med->getName());
		if(IOHelper::sendRequest(client->getSocket(),buffer)) /* Vérification échec */
		{
			/* Abandon */
			return;
		}
	}

}


/***
Envoie les infos sur le médicament au numéro donné
***/
void MedRequest::sendMedInfo(Client * client, int id)
{
	Logger::log("Info asked on med %d... \n", id);
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

	/* Envoi du reste des infos (comme défini par le protocol) */
	sprintf(buffer,"PoidBase%d Unite%d Compte%d Max%d Position%d\n",selectedMed->getBaseWeigth(),selectedMed->getUnitWeigth(),selectedMed->getCurrentCount(), selectedMed->getMaxCount(), selectedMed->getLocation());
	if(IOHelper::sendRequest(client->getSocket(),buffer)) 
	{
		/* Abandon */
		return;
	}
}

/***
Envoie le nom de l'img du médicament au numéro donné
***/
void MedRequest::sendMedImg(Client * client, int id)
{
	Logger::log("Img asked on med %d... \n", id);
	/* Création du buffer de communication */
	char buffer[1024];

	/* Récupération du médicament demandé */
	Med * selectedMed = medHandler->getMed(id);
	
	/* Envoi du nom (comme défini par le protocol) */
	sprintf(buffer,"%s\n",selectedMed->getImg());
	if(IOHelper::sendRequest(client->getSocket(),buffer)) 
	{
		/* Abandon */
		return;
	}

}

/***
Envoie le nombre de médicament du numéro donné
***/
void MedRequest::sendMedCount(Client * client, int id)
{
	Logger::log("Count asked on med %d... \n", id);
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


void MedRequest::handleRequest(char * request, Client * client)
{
		/* Comparaisons */
	
	if(strlen(request) >= 16 && memcmp(request, "ListerMedicaments", 17) == 0)
	{
		/* On envoie la liste des médicaments */
		sendMedList(client);
	}
	else if(strlen(request) >= 13 && memcmp(request, "ImgMedicament", 13) == 0)
	{
		/* On récupère le numéro dans la requête*/
		int id;
		sscanf(request,"ImgMedicament%d\n",&id);
		
		/* On envoie l'image demandée*/
		sendMedImg(client,id);
	}
	else if(strlen(request) >= 13 && memcmp(request, "NombreMedicament", 16) == 0)
	{
		/* On récupère le numéro dans la requête*/
		int id;
		sscanf(request,"NombreMedicament%d\n",&id);
		
		/* On envoie l'image demandée*/
		sendMedCount(client,id);
	}
	else if(strlen(request) >= 15 && memcmp(request, "InfoMedicaments", 15) == 0)
	{
		/* On récupère le numéro dans la requête */		
		int id;
		sscanf(request,"InfoMedicaments<%d\n",&id);
		
		/* On envoie les info sur le médicament */
		sendMedInfo(client,id);
	}
	else
	{
		Logger::log("Unknow request !!!\n");
		/* Échec */
	}
}