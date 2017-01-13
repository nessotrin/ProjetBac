#include "MedHandler.h"

#include <unistd.h>

MedHandler::MedHandler()
{
	medList = NULL;
	medCount = 0;
	iteratorCounter = 0;
}

int MedHandler::getMedCount()
{
	return medCount;
}

bool MedHandler::iterateOnMeds(Med ** medToUse)
{
	if(iteratorCounter >= medCount)
	{
		iteratorCounter = 0;
		return false;
	}
	else
	{
		*medToUse = medList+iteratorCounter;
		iteratorCounter++;
		return true;
	}
}