#include "MedRequest.h"

#include "IOHelper.h"

#include <cstdio>

MedRequest::MedRequest(MedHandler * newMedHandler)
{
	medHandler = newMedHandler;
}

void MedRequest::sendMedList(Client * client)
{
	printf("Medlist asked ... \n");
	char buffer[1024];
	
	sprintf(buffer, "Nombre%d\n",medHandler->getMedCount());
	if(IOHelper::sendRequest(client->getSocket(),buffer))
	{
		return;
	}
	
	Med * med;
	while(medHandler->iterateOnMeds(&med))
	{
		sprintf(buffer, "%s\n",med->getName());
		if(IOHelper::sendRequest(client->getSocket(),buffer))
		{
			return;
		}
	}

		
}