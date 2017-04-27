#include "LedDriver.h"

#include "BBBiolib.h"

#include <cstdio>
#include <unistd.h>

LedDriver::LedDriver()
{
	realtimeCount = 0;
	
	
	
	
	
}

void LedDriver::work()
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
			if(realtimeCount <= leds[i].value[j])
			{
				leds_RealtimeBool[i].value[j] = 1;
			}
			else
			{
				leds_RealtimeBool[i].value[j] = 0;			
			}
		}
	}
	
	writeLedRealtime();
}

void LedDriver::ledOn()
{
	for(int i = 0 ; i < LED_COUNT ; i++)
	{
		for(int j = 0 ; j < 3 ; j++)
		{
			leds[i].value[j] = 255;
		}
	}
}

void LedDriver::ledOff()
{
	for(int i = 0 ; i < LED_COUNT ; i++)
	{
		for(int j = 0 ; j < 3 ; j++)
		{
			leds[i].value[j] = 0;
		}
	}	
}

void LedDriver::pointTo(int id)
{
	for(int j = 0 ; j < 3 ; j++)
	{
		leds[id].value[j] = 128;
	}
}

void LedDriver::emergencyFlash()
{
	printf("EMERGENCY FLASH LED\n");
	
	unsigned char value = 0;

	for(int i = 0 ; i < 2*10 ; i++)
	{
		for(int j = 0 ; j < LED_COUNT ; j++)
		{
			leds[j].value[R] = value;
			leds[j].value[G] = 0;
			leds[j].value[B] = 0;
		}
		value = ~value;
		sleep(0.5);
	}
}


void LedDriver::writeLedRealtime()
{
	for(int i = 0 ; i < LED_COUNT ; i++)
	{
		for(int j = 0 ; j < 3 ; j++)
		{
			pin_low(8,12);
			if(leds[i].value[j])
			{
				pin_high(8,45);		
			}
			else
			{
				pin_low(8,45);						
			}
			usleep(10);
			pin_high(8,44);
		}
	}
}


