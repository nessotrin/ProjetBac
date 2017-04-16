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
	{"RecupNomMedecin",(int)strlen("RecupNomMedecin"),Aucun,HUMAN_REQUEST}, //OK
	{"RecupIdAutorisesMedecin",(int)strlen("RecupIdAutorisesMedecin"),Aucun,HUMAN_REQUEST}, //50%
	{"RecupPoidsUnitaireMedoc",(int)strlen("RecupPoidsUnitaireMedoc"),Aucun,MED_REQUEST}, //OK
	{"RecupImageMedoc",(int)strlen("RecupImageMedoc"),Aucun,MED_REQUEST}, //50%
	{"RecupNomMedoc",(int)strlen("RecupNomMedoc"),Aucun,MED_REQUEST}, //OK
	{"RecupNombreMedoc",(int)strlen("RecupNombreMedoc"),Aucun,MED_REQUEST}, //OK
	{"RecupTailleListeMedoc",(int)strlen("RecupTailleListeMedoc"),Aucun,MED_REQUEST}, //OK	
	{"RecupIdMedoc",(int)strlen("RecupIdMedoc"),Aucun,MED_REQUEST}, //OK
	{"RecupDateMedoc",(int)strlen("RecupDateMedoc"),Aucun,DOOR_REQUEST}, //OK
	{"RecupEtatPorte",(int)strlen("RecupEtatPorte"),Aucun,DOOR_REQUEST}, //TRIAGING TO DO
	{"OuvrirPorte",(int)strlen("OuvrirPorte"),Aucun,DOOR_REQUEST},  //TRIAGING TO DO
	{"FermerPorte",(int)strlen("FermerPorte"),Aucun,DOOR_REQUEST}, //1%
	{"LEDOn",(int)strlen("LEDOn"),Aucun,LED_REQUEST}, //move to client
	{"LEDOff",(int)strlen("LEDOff"),Aucun,LED_REQUEST}, //move to client
	{"CapteurOn",(int)strlen("CapteurOn"),Capteurs,SENSOR_REQUEST}, 
	{"CapteurOff",(int)strlen("CapteurOff"),Capteurs,SENSOR_REQUEST},
	{"ChangerPoidsUnitaireMedoc",(int)strlen("ChangerPoidsUnitaireMedoc"),Capteurs,MED_REQUEST},
	{"ChangerNombreMedoc",(int)strlen("ChangerNombreMedoc"),Capteurs,MED_REQUEST},
	{"ResultatCoherencePoid",(int)strlen("ResultatCoherencePoid"),Alarme,NO_REQUEST},
	{"DeclencherAlarme",(int)strlen("DeclencherAlarme"),Alarme,NO_REQUEST},
	{"AllumerLumieresAlarme",(int)strlen("AllumerLumieresAlarme"),Leds,NO_REQUEST},
	{"EnvoyerMailAlarme",(int)strlen("EnvoyerMailAlarme"),AlarmeMail,NO_REQUEST},
	{"VerifierIdCarte",(int)strlen("VerifierIdCarte"),Aucun,HUMAN_REQUEST},
	{"MedecinConnecte",(int)strlen("MedecinConnecte"),Ecran,NO_REQUEST},
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


