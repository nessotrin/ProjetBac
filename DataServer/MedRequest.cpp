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

/*	TODO

	sprintf(buffer, "Nombre%d\n",medHandler->getMedCount());
	if(IOHelper::sendRequest(client->getSocket(),buffer)) 
	{
		return;
	}
*/
}