#include "LoginProtocol.h"

#include "TextResolver.h"

#include "Logger.h"


#include <cstring>
#include <cstdio>

/***
S'occupe de connecter un client
Retourne 'true' si il y a eut un problème
***/
bool LoginProtocol::doLogin(Client * client)
{
	/* Crée le buffer de communication*/
	unsigned char buffer[64];
	
	/* Reçoit le message de 'login' */
	int length = client->receiveData(buffer,64);
	
	/* Vérifications sur le message */
	if(length < 64) /* Le message est trop court, il s'agit  probablement d'un autre logiciel qui tente de se connecter */
	{
		Logger::log("Client didn't send enough login data ! (%d/%d)\n",length,64);
		
		/* Échec */
		return true;
	}
	
	/* Vérification du 'challenge' */
	if(memcmp(buffer,"<3COOKIE",8) != 0) /* Le 'magic' ne correspond pas*/
	{
		/* Affichage du 'magic' qui a été reçu */
		Logger::log("Client has the wrong magic !\n");
		Logger::log("\"");
		for(int i = 0 ; i < 8 ; i++)
		{
			Logger::log("%c",buffer[i]);
		}
		Logger::log("\"\n");
		
		/* Échec */
		return true;
	}
	
	/* Affichage des infos du client*/
	Logger::log("Info module:\nType %s\nVersion %d.%d.%d\nDebug: %s\n",TextResolver::typeToName(buffer[8]),buffer[9],buffer[10],buffer[11],TextResolver::boolToFrench(buffer[12]));
	
	/* On enregistre les informations dans l'objet client*/
	client->setType(buffer[8]);
	client->setDebug(buffer[12]);
	
	/* Réussite */
	return false;
}
