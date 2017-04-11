#ifndef _SENSOR_REQUEST_H_
#define _SENSOR_REQUEST_H_

#include "Client.h"

#include "Med.h"

#include "SensorHandler.h"

class SensorRequest
{
public:
	SensorRequest(SensorHandler * newSensorHandler);

	void enableSensors(Client * client);
	void disableSensors(Client * client);

	void warnOfChange();
	
	bool checkConsistancy(Med * medTaken, int count);

	void handleRequest(char * request, Client * client);

private:
	
	SensorHandler * sensorHandler;

};

#endif // _SENSOR_REQUEST_H_