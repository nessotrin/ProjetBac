#include "LedHandler.h"

#include "Logger.h"

LedHandler::LedHandler()
{

}

/*  TODO: MOVE TO CLIENT !!!*/

void LedHandler::work()
{
	realtimeCount++;
	if(realtimeCount > 255)
	{
		realtimeCount = 1;
	}
	
	for(int i = 0 ; i < LED_COUNT ; i++)
	{
		for(int j = 0 ; j < 3 ; j++)
		{
			if(realtimeCount <= Leds[i].value[j])
			{
				Leds_RealtimeBool[i].value[j] = 1;
			}
			else
			{
				Leds_RealtimeBool[i].value[j] = 0;			
			}
		}
	}
	
	writeLedRealtime();
}

void LedHandler::LedOn()
{
	for(int i = 0 ; i < LED_COUNT ; i++)
	{
		for(int j = 0 ; j < 3 ; j++)
		{
			Leds[i].value[j] = 255;
			Leds[i].value[j] = 255;
			Leds[i].value[j] = 255;
		}
	}
}

void LedHandler::LedOff()
{
	for(int i = 0 ; i < LED_COUNT ; i++)
	{
		for(int j = 0 ; j < 3 ; j++)
		{
			Leds[i].value[j] = 0;
			Leds[i].value[j] = 0;
			Leds[i].value[j] = 0;
		}
	}	
}

void LedHandler::PointTo(int id)
{
	Logger::log("Set point to color : TODO !\n");
	for(int j = 0 ; j < 3 ; j++)
	{
		Leds[id].value[j] = 128;
		Leds[id].value[j] = 128;
		Leds[id].value[j] = 128;
	}
}

void LedHandler::EmergencyFlash()
{
	Logger::log("EMERGENCY FLASH LED : TODO !\n");
}


void LedHandler::writeLedRealtime()
{
	Logger::log("writeLedRealtime: TODO !\n");
}


