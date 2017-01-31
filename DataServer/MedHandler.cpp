#include "MedHandler.h"

#include <unistd.h>
#include <cstdio>

MedHandler::MedHandler()
{
	/* Initialise les valeurs à 0 */
	medList = NULL;
	medCount = 0;
	iteratorCounter = 0;
}

int MedHandler::getMedCount()
{
	return medCount;
}

/***
Permet d'itérer sur les médicaments
L'appelant donne un pointeur de pointeur dans lequel sera placé le pointeur vers le medicament
La fonction retourne 'True' tant que tout les clients ne sont pas passés
***/
bool MedHandler::iterateOnMeds(Med ** medToUse)
{
	printf("Iterating at %d/%d\n",iteratorCounter,medCount);

	/* Vérification de la progression */

	if(iteratorCounter >= medCount)
	{
		/* Retour à 0 */
		iteratorCounter = 0;
		/* On préviens que tout à été traversé */
		return false;
	}
	else
	{
		/* On place le pointeur vers le médicament */
		*medToUse = medList[iteratorCounter];
		/* On avance d'un */
		iteratorCounter++;
		/* On préviens de continuer*/
		return true;
	}
}

/***
Permet de récupérer un médicament par son numéro
***/
Med * MedHandler::getMed(int id)
{
	/* retourne un pointeur vers le médicament*/
	return medList[id];
}