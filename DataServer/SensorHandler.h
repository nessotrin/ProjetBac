#ifndef _SENSOR_HANDLER_H_
#define _SENSOR_HANDLER_H_

#include "Med.h"

class weigthRange
{
	public:
	
	weigthRange(int newMin, int newMax)
	{
		min = newMin;
		max = newMax;
	}
	
	int min;
	int max;
};

class SensorHandler
{
public:
	weigthRange computeWeigthRange(Med * med, int count);

};

#endif // _SENSOR_HANDLER_H_
