#include <iostream>

#include <ConnectionServeur.h>

#include <cstdio>
#include <unistd.h>
#include <cstdlib>
#include <cstring>

#include "OpenGLHolder.h"
#include "MenuWorker.h"
#include "GlobalTexture.h"

/***
Récupère la liste des medicaments à partir du serveur
***/
Medicament * recupererListeMedicament()
{
	/* Création du buffer qui servivra au messages */
	char message[1024];
	
	/* Demande la liste des medicaments au serveur */
	sprintf(message,"ListerMedicaments\n");
	if(ConnectionServeur::envoyer(message))
	{
		return NULL;
	}
	
	/* Reçoit une réponse */
	char * reponse = ConnectionServeur::recevoir();
	if(reponse == NULL)
	{
		return NULL;
	}
	
	/* Analyse la réponse */
	int nombreDeMed;
	if(sscanf(reponse,"Nombre%d\n",&nombreDeMed) == EOF)
	{
		printf("SSCANF ERROR\n");
		return NULL;
	}
	free(reponse);

	/* Il y a x medicaments */
	printf("%d Médicaments\n",nombreDeMed);
	
	/* Allocation mémoire de la liste de médicament avec la bonne taille */
	Medicament * listeMeds = (Medicament *) malloc(sizeof(Medicament)*nombreDeMed);
	if(listeMeds == NULL)
	{
		printf("FAILED TO ALLOCATE\n");
		return NULL;
	}
		
	/* Pour chaque medicament */
	for(int i = 0 ; i < nombreDeMed ; i++)
	{
		/* On reçoit le nom */
		reponse = ConnectionServeur::recevoir();
		if(reponse == NULL)
		{
			return NULL;
		}
		reponse[strlen(reponse)-1] = 0; // retirer le \n
		/* On donne au medicament son nom */
		listeMeds->nom = reponse;
	}
	
	/* On retourne la liste complète des medicaments */
	return listeMeds;
}


/***
Se connecte et lance l'interface
***/

#include "GLHelper.h"

#include "FontRenderer.h"

int main(int argc, char **argv)
{
    std::cout << "User interface" << std::endl;

	OpenGLHolder openGLHolder;
	openGLHolder.initGraphics();

	if(FontRenderer::loadFonts())
	{
		return 1;
	}
	
	GlobalTexture::load();
	
	/* On initialise la connection au seveur et on écrit le résultat */
	//printf("%d\n",ConnectionServeur::initialisation("127.0.0.1",Ecran,0,0,1,true));
	
	//recupererListeMedicament();
	
	MenuWorker menuWorker(&openGLHolder);
	menuWorker.work();
	
	/* On attends avant de fermer */
	sleep(3);
	
	/* On se déconnecte du serveur */
	ConnectionServeur::fermer();
		
    return 0;
}
