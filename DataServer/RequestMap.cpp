#include "RequestMap.h"
#include "Logger.h"

#include <cstring>
#include <cstdio>

class Request
{
	public:
		Request(char * newCmdName, int newCmdLendth, int newBroadcastTo, int newDesignatedHandler)
		{
			cmdName = newCmdName;
			cmdLength = newCmdLendth;
			broadcastTo = newBroadcastTo;
			designatedHandler = newDesignatedHandler;
		}
		
		char * cmdName; //without parameters
		int cmdLength; //length without parameters
		int broadcastTo; //-1 = no broadcast
		int designatedHandler;
};



#define REQUEST_MAP_SIZE 25

Request requestList[REQUEST_MAP_SIZE] = 
{
	{"RecupIdMedecin",17,Aucun,MED_HANDLER},
	{"RecupNomMedecin",17,Aucun,MED_HANDLER},
	{"RecupIdAutorisesMedecin",17,Aucun,MED_HANDLER},
	{"RecupPoidsUnitaireMedoc",13,Aucun,MED_HANDLER},
	{"RecupImageMedoc",16,Aucun,MED_HANDLER},
	{"RecupNomMedoc",13,Aucun,MED_HANDLER},
	{"RecupNombreMedoc",15,Aucun,MED_HANDLER},	
	{"RecupTailleListeMedoc",15,Aucun,MED_HANDLER},	
	{"RecupIdMedoc",17,Aucun,MED_HANDLER},
	{"RecupDateMedoc",13,Aucun,MED_HANDLER},
	{"RecupEtatPorte",16,Aucun,MED_HANDLER},
	{"OuvrirPorte",16,VerrouPorte,MED_HANDLER},
	{"FermerPorte",16,VerrouPorte,MED_HANDLER},
	{"LEDOn",15,Leds,MED_HANDLER},
	{"LEDOff",17,Leds,MED_HANDLER},
	{"CapteurOn",13,Capteurs,MED_HANDLER},
	{"CapteurOff",16,Capteurs,MED_HANDLER},
	{"ChangerPoidsUnitaireMedoc",15,Capteurs,MED_HANDLER},
	{"ChangerNombreMedoc",17,Capteurs,MED_HANDLER},
	{"EnvoieCarteId",13,NFC,MED_HANDLER},
	{"EnvoieNombreMedocDeclare",16,Capteurs,MED_HANDLER},
	{"EnvoieNombreMedocReel",15,Aucun,MED_HANDLER},
	{"DeclencherAlarme",15,Alarme,MED_HANDLER},
	{"AllumerLumieresAlarme",15,Leds,MED_HANDLER},
	{"EnvoyerMailAlarme",15,AlarmeMail,MED_HANDLER},
	{"VerifierIdCarte",15,VerrouPorte,MED_HANDLER},
};

void RequestMap::initRequestMap()
{
}

int RequestMap::getBroadcastTo(char * request)
{
	for(int i = 0 ; i < REQUEST_MAP_SIZE ; i++)
	{
		if(strlen(request) >= requestList[i].cmdLength && memcmp(request,requestList[i].cmdName, requestList[i].cmdLength) == 0)
		{
			return requestList[i].broadcastTo;
		}
	}
	
	return Aucun;
}

int RequestMap::getDesignatedHandler(char * request)
{
	for(int i = 0 ; i < REQUEST_MAP_SIZE ; i++)
	{
		Logger::log("Testing \"%s\" (%d) with \"%s\" (%d)\n",request,strlen(request),requestList[i].cmdName, requestList[i].cmdLength);
		if(strlen(request) >= requestList[i].cmdLength && memcmp(request,requestList[i].cmdName, requestList[i].cmdLength) == 0)
		{
			return requestList[i].designatedHandler;
		}
	}
	
	return NO_HANDLER;
}


