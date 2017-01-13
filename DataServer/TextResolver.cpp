#include "TextResolver.h"

char * TextResolver::typeToName(int type)
{
	switch(type)
	{
		case 0:
			return "Ecran";
		default:
			return "INCONNU";
	}
}

char * TextResolver::boolToFrench(bool value)
{
	if(value)
	{
		return "Oui";
	}
	else
	{
		return "Non";
	}
}
