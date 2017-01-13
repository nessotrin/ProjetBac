#ifndef _CONNECTION_SERVEUR_H_
#define _CONNECTION_SERVEUR_H_

#include <ConnectionHandler.h>

enum
{
	Ecran = 0,
	Codeur,
	Leds,
	Verrou,
	Carte,
	WEB,
	Alarme,
	SMS,
	Poids,
	debug,
} typeList;

#define PORT 65534

class ConnectionServeur
{
public:
	static bool initialisation(char * ip, int newType, int newVersionMajor, int newVersionMinor, int newVersionPatch, bool newIsDebug);
private:


	static ConnectionHandler connectionHandler;
};

#endif // _CONNECTION_SERVEUR_H_
