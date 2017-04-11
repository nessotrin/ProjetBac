#include "HumanHandler.h"

#include <cstdio>
#include <cstdlib>

HumanHandler::HumanHandler()
{
	/* initialise les valeurs à 0*/
	humanList = NULL;
	humanCount = 0;
	iteratorCounter = 0;
}

/***
Retourne le nombre d'humains dans la base de données
***/
int HumanHandler::getHumanCount()
{
	return humanCount;
}

/***
Permet d'itérer sur les humains
L'appelant donne un pointeur de pointeur dans lequel sera placé le pointeur vers le medicament
La fonction retourne 'True' tant que tout les clients ne sont pas passés
***/
bool HumanHandler::iterateOnHumans(Human ** humanToUse)
{
	/* Vérification de la progression */
	if(iteratorCounter >= humanCount)
	{
		/* Retour à 0 */
		iteratorCounter = 0;
		/* On préviens que tout à été traversé */
		return false;
	}
	else
	{
		/* On place le pointeur vers le médicament */
		*humanToUse = humanList[iteratorCounter];
		/* On avance d'un */
		iteratorCounter++;
		/* On préviens de continuer*/
		return true;
	}
}

/***
Permet de récupérer un humain par son numéro
***/
Human * HumanHandler::getHuman(int id)
{
	/* retourne un pointeur vers l'humain*/
	return humanList[id];
}

void HumanHandler::addHuman(Human * newHuman)
{
	humanList = (Human **) realloc(humanList, sizeof(Human *)*(humanCount+1));
	humanList[humanCount] = newHuman;
	humanCount++;
}

