#include "ConnectionServeur.h"

#include "ModuleInfo.h"
#include "IOHelper.h"
#include "NetworkLogger.h"

#include <cstdio>

ConnectionHandler ConnectionServeur::connectionHandler;
/***
Initialise la connection sur le serveur, avec le nom, le type de programme, la version, et le mode 'debug'
 ***/
bool ConnectionServeur::initialisation(char * ip, TypeList newType, int newVersionMajor, int newVersionMinor, int newVersionPatch, bool newIsDebug)
{
	printf("Init sur \"%s\"\n",ip);
	
	/* Crée et remplie la structure contenant les info sur le programme */
	ModuleInfo info;
	info.type = newType;
	info.versionMajor = newVersionMajor;
	info.versionMinor = newVersionMinor;
	info.versionPatch = newVersionPatch;
	info.isDebug = newIsDebug;

	/* Se connecte à l'IP donnée avec le port donné*/
	if(connectionHandler.connectToIP(ip,PORT))
	{
		printf("Failed to connect to given IP, fallback to localhost\n");
		/* En cas d'échec, se connecte à lui même avec le port donné */
		if(connectionHandler.connectToIP("127.0.0.1",PORT))
		{
			printf("CRITICAL Failed to connect the server !\n");
			return true;
		}
	}

	/* S'identifie et passe le challenge */
	connectionHandler.doLogin(info);

	return false;
}

/***
Envoie un message au serveur à l'aide des fonctions avancées
***/
bool ConnectionServeur::envoyer(char * message)
{
	return IOHelper::sendRequest(connectionHandler.getSocket(),message);
}

/***
Recoie un message du serveur à l'aide des fonctions avancées
***/
char * ConnectionServeur::recevoir()
{
	return IOHelper::getRequest(connectionHandler.getSocket());
}

/***
Vérifie si il y a un message prêt à être reçu
***/
bool ConnectionServeur::verifRecevoirPret()
{
	return connectionHandler.checkForData();
}

/***
Ferme la connection au serveur à l'aide des fonctions avancées
***/
void ConnectionServeur::fermer()
{
	connectionHandler.disconnect();
}

char * logLevelPrefix[] = { "[INFO]: ",
							"[ERROR]: ",
							"[WARNING]: ",
							"[SPECIAL] _\\/_\n\\  /\n\\/ \n->"};

bool ConnectionServeur::serveurPrintf(LogLevel logLevel, const char * format ...)
{
	char buffer[1024];
	
	int writePos = sprintf(buffer, "LogSurServeur ");
	
	writePos += sprintf(buffer+writePos, "%s", logLevelPrefix[logLevel]);

	


	
	va_list args;
	
	va_start (args, format);
	vsprintf (buffer+writePos, format, args);
	printf("\"");
	vprintf (format, args);
	printf("\"\n");

	va_end (args);
	
	NetworkLogger::log(connectionHandler.getSocket(), buffer);
	
	return false;
}