#include "TextResolver.h"

char * TextResolver::typeToName(int type)
{
	switch(type)
	{
		case 0:
			return (char *)"Ecran de commande";
		case 1:
			return (char *)"Codeur roratif";
		case 2:
			return (char *)"Leds d'indication";
		case 3:
			return (char *)"Verrou";
		case 4:
			return (char *)"Lecteur de carte NFC";
		case 5:
			return (char *)"Interface WEB";
		case 6:
			return (char *)"Alarme sonore";
		case 7:
			return (char *)"Module SMS";
		case 8:
			return (char *)"Capteurs de poid";
		case 9:
			return (char *)"Module debug";
		default:
			return (char *)"INCONNU /!\\";
	}
}

char * TextResolver::boolToFrench(bool value)
{
	if(value)
	{
		return (char *)"Oui";
	}
	else
	{
		return (char *)"Non";
	}
}
