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



#define REQUEST_MAP_SIZE 24

Request requestList[REQUEST_MAP_SIZE] = 
{
	{"RecupNomMedecin",15,Aucun,HUMAN_REQUEST}, //OK
	{"RecupIdAutorisesMedecin",23,Aucun,HUMAN_REQUEST}, //50%
	{"RecupPoidsUnitaireMedoc",13,Aucun,MED_REQUEST}, //OK
	{"RecupImageMedoc",16,Aucun,MED_REQUEST}, //50%
	{"RecupNomMedoc",13,Aucun,MED_REQUEST}, //OK
	{"RecupNombreMedoc",15,Aucun,MED_REQUEST}, //OK
	{"RecupTailleListeMedoc",15,Aucun,MED_REQUEST}, //OK	
	{"RecupIdMedoc",17,Aucun,MED_REQUEST}, //OK
	{"RecupDateMedoc",13,Aucun,DOOR_REQUEST}, //OK
	{"RecupEtatPorte",16,Aucun,DOOR_REQUEST}, //TRIAGING TO DO
	{"OuvrirPorte",16,Aucun,DOOR_REQUEST},  //TRIAGING TO DO
	{"FermerPorte",16,Aucun,DOOR_REQUEST}, //1%
	{"LEDOn",15,Aucun,LED_REQUEST}, //move to client
	{"LEDOff",17,Aucun,LED_REQUEST}, //move to client
	{"CapteurOn",13,Capteurs,SENSOR_REQUEST}, 
	{"CapteurOff",16,Capteurs,SENSOR_REQUEST},
	{"ChangerPoidsUnitaireMedoc",15,Capteurs,MED_REQUEST},
	{"ChangerNombreMedoc",17,Capteurs,MED_REQUEST},
	{"ResultatCoherencePoid",21,Alarme,NO_REQUEST},
	{"DeclencherAlarme",15,Alarme,NO_REQUEST},
	{"AllumerLumieresAlarme",15,Leds,NO_REQUEST},
	{"EnvoyerMailAlarme",15,AlarmeMail,NO_REQUEST},
	{"VerifierIdCarte",15,Aucun,HUMAN_REQUEST},
	{"MedecinConnecte",15,Ecran,NO_REQUEST},
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

int RequestMap::getDesignatedRequestHandler(char * request)
{
	for(int i = 0 ; i < REQUEST_MAP_SIZE ; i++)
	{
		Logger::log("Testing \"%s\" (%d) with \"%s\" (%d)\n",request,strlen(request),requestList[i].cmdName, requestList[i].cmdLength);
		if(strlen(request) >= requestList[i].cmdLength && memcmp(request,requestList[i].cmdName, requestList[i].cmdLength) == 0)
		{
			return requestList[i].designatedHandler;
		}
	}
	
	return NO_REQUEST;
}


