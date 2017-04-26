/*
#include "RequestMap.h"
#include "Logger.h"

#include <cstring>
#include <cstdio>






RequestDefinition requestList[]=
{
	{"RecupNomMedecin",HUMAN_REQUEST},
	{"RecupIdAutorisesMedecin",HUMAN_REQUEST},
	{"RecupPoidsUnitaireMedoc",MED_REQUEST},
	{"RecupImageMedoc",MED_REQUEST},
	{"RecupNomMedoc",MED_REQUEST},
	{"RecupNombreMedoc",MED_REQUEST},
	{"RecupTailleListeMedoc",MED_REQUEST},
	{"RecupDateMedoc",MED_REQUEST},
	{"RecupEtatPorte",BROADCAST_REQUEST},
	{"OuvrirPorte",BROADCAST_REQUEST},
	{"FermerPorte",BROADCAST_REQUEST},
	{"LEDOn",BROADCAST_REQUEST},
	{"LEDOff",BROADCAST_REQUEST},
	{"CapteurOn",BROADCAST_REQUEST},
	{"CapteurOff",BROADCAST_REQUEST},
	{"ChangerPoidsUnitaireMedoc",MED_REQUEST},
	{"ChangerNombreMedoc",MED_REQUEST},
	{"VerifierCoherencePoid",BROADCAST_REQUEST},
	{"LumiereMontrerMed",BROADCAST_REQUEST},
	{"EnvoyerMailAlarme",BROADCAST_REQUEST},
	{"DeclencherAlarme",BROADCAST_REQUEST},
	{"AllumerLumieresAlarme",BROADCAST_REQUEST},
	{"MedecinConnecte",BROADCAST_REQUEST},
	{"LogSurServeur ",LOG_REQUEST},
	{"",-1}
};



int RequestMap::getHandlerId(char * request)
{
	int i = 0;
	while(requestList[i].handlerId != -1)
	{
		Logger::log("Testing \"%s\" (%d) with \"%s\"\n",InfoLog,request,strlen(request),requestList[i].name);
		if(strlen(request) >= strlen(requestList[i].name) && memcmp(request,requestList[i].name, strlen(requestList[i].name)) == 0)
		{
			Logger::log("FOUND\n",InfoLog);
			return requestList[i].handlerId;
		}
	}
	
	return -1;
}


*/