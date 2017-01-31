#include "MedRequest.h"

#include "IOHelper.h"

#include <cstdio>

MedRequest::MedRequest(MedHandler * newMedHandler)
{
	medHandler = newMedHandler;
}


/***
Envoie la liste complète des médicaments et leurs info
***/
void MedRequest::sendMedList(Client * client)
{
	printf("Medlist asked ... \n");
	/* Création du buffer de communication */
	char buffer[1024];
	
	/* Création et envoie d'un message donnant le nombre total de médicaments */
	sprintf(buffer, "Nombre%d\n",medHandler->getMedCount());
	if(IOHelper::sendRequest(client->getSocket(),buffer)) /* Vérification échec */
	{
		/* Abandon */
		return; 
	}
	
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
	printf("Info asked on med %d... \n", id);
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