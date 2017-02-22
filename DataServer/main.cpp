#include "Server.h"
#include "RequestHandler.h"


#include <stdio.h>


#define VERSION_MAJOR 0
#define VERSION_MINOR 1

#define SERVER_PORT 65534


/* Fonction d'entrée du serveur */
int main(int argc, char **argv)
{
	printf("DataBaser Server V%d.%d\n",VERSION_MAJOR,VERSION_MINOR);
	
	printf("Initializing med handler ...\n");
	
	/* Création des gestionnaires de médicament et de clients*/
	MedHandler medHandler; 
	LoginHandler loginHandler;
	
	/* Création du gestionnarie de requête de médicament */
	MedRequest medRequest(&medHandler);

	/* Création du gestionnaire de reqûete global */
	RequestHandler requestHandler(&loginHandler,&medRequest);

	/* Création du serveur */
	Server server(SERVER_PORT, &loginHandler, &requestHandler);

	Med * testMed = new Med("PROCRASTINATION 1000KG");
	Med * newTestMed = new Med("JPEUT_PAS_BOUFFER_JE_TE_HAIS");
	
	testMed->setImg("http://www.luvbat.com/uploads/kitten_in_a_box_1983471666.jpg");
	newTestMed->setImg("https://upload.wikimedia.org/wikipedia/commons/thumb/9/9c/Middle_finger_BNC.jpg/250px-Middle_finger_BNC.jpg");

	medHandler.addMed(testMed);
	medHandler.addMed(newTestMed);
	

	printf("Setuping database ...\n");

	
	printf("Setup'ing server ...\n");

	/* Mise en place du serveur */
	if(server.setup())
	{
		return 1;
	}
	
	printf("Starting client handling ...\n");
	
	/* Lancement du serveur */
	server.work();
	
	
	return 0;
}