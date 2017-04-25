#ifndef _CONNECTION_SERVEUR_H_
#define _CONNECTION_SERVEUR_H_

#include <ConnectionHandler.h>

#include <stdarg.h>

enum TypeList
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
};


enum LogLevel
{
	information = 0,
	erreur = 1,
	special,
};

struct Medicament
{
	char * nom;
	int poidDeBase;
	int poidUnite;
	int compte;
	int maximum;
	int position;
};

typedef Medicament Medicament;


#define PORT 65534

class ConnectionServeur
{
public:
	static bool initialisation(char * ip, TypeList newType, int newVersionMajor, int newVersionMinor, int newVersionPatch, bool newIsDebug);
	static bool envoyer(char * message);
	static char * recevoir();
	static bool verifRecevoirPret();
	static void fermer();
	static bool serveurPrintf(LogLevel logLevel, const char * format ...);


private:


	static ConnectionHandler connectionHandler;
	

};

#endif // _CONNECTION_SERVEUR_H_
