#include "Server.h"
#include "RequestHandler.h"


#include <stdio.h>


#define VERSION_MAJOR 0
#define VERSION_MINOR 1

#define SERVER_PORT 65534

#include "Logger.h"

#include <cstdlib>

#include <time.h>

#include "RequestMap.h"

/* Fonction d'entrée du serveur */
int main(int argc, char **argv)
{
	RequestMap::initRequestMap();
	Logger::initLogger();
	Logger::initFile("log.txt");
	
	Logger::log("DataBaser Server V%d.%d\n",VERSION_MAJOR,VERSION_MINOR);
	
	Logger::log("Initializing handlers ...\n");
	
	/* Création des gestionnaires de médicament et de clients*/
	MedHandler medHandler; 
	HumanHandler humanHandler; 
	LoginHandler loginHandler;
	
	/* Création du gestionnarie de requête de médicament */
	MedRequest medRequest(&medHandler);
	HumanRequest humanRequest(&humanHandler);

	/* Création du gestionnaire de reqûete global */
	RequestHandler requestHandler(&medRequest, &humanRequest);

	/* Création du serveur */
	Server server(SERVER_PORT, &loginHandler, &requestHandler);

	Logger::log("Setuping database ...\n");

	/* TESTS */
	/* initialize random seed: */
	srand (time(NULL));
	Med * testMed1 = new Med("Doliprane");
	Med * testMed2 = new Med("Dafalgan");
	Med * testMed3 = new Med("Corde+Tabouret");
	testMed1->setImg("icon_medication1.png");
	testMed1->setCurrentCount(rand()%10);
	testMed2->setImg("icon_medication2.png");
	testMed2->setCurrentCount(rand()%10);
	testMed3->setImg("icon_medication3.png");
	testMed3->setCurrentCount(rand()%10);
	medHandler.addMed(testMed1);
	medHandler.addMed(testMed2);
	medHandler.addMed(testMed3);


	for(int i = 4 ; i <= 7 ; i++)
	{
		char name[50];
		sprintf(name, "Medicament %d",i);
		Med * tmpMed = new Med(name);
		tmpMed->setImg("https://placeholdit.imgix.net/~text?txtsize=28&bg=0099ff&txtclr=ffffff&txt=300%C3%97300&w=300&h=300&fm=png");
		tmpMed->setCurrentCount(rand()%10);
		medHandler.addMed(tmpMed);
	}
	
	
	Logger::log("Setup'ing server ...\n");

	/* Mise en place du serveur */
	if(server.setup())
	{
		return 1;
	}
	
	Logger::log("Starting client handling ...\n");
	
	/* Lancement du serveur */
	server.work();
	
	
	return 0;
}