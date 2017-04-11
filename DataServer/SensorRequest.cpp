#include "SensorRequest.h"

#include "Logger.h"

#include <cstdlib>
#include <cstring>


SensorRequest::SensorRequest(SensorHandler * newSensorHandler)
{
	sensorHandler = newSensorHandler;
}



void SensorRequest::handleRequest(char * request, Client * client)
{
		/* Comparaisons */
		
	Logger::log("handleRequest with SENSOR_REQUEST\n");
		
	if(strlen(request) >= 13 && memcmp(request, "VerifierPrise", 13) == 0)
	{
		sensorHandler->computeWeigthRange(0,0);
		Logger::log("Virifier prise request TODO !!\n");		
	}
	else
	{
		Logger::log("Unknow request !!!\n");
		/* Échec */
	}
}
