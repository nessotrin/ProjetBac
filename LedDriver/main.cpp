#include "ConnectionServeur.h"

#include "LedDriver.h"

#include "BBBiolib.h"

#include <cstdio>
#include <unistd.h>
#include <cstring>

int main(int argc, char** argv)
{
	if(ConnectionServeur::initialisation("127.0.0.1",Leds,0,0,1,1))
	{
		printf("FAILED TO CONNECT TO THE SERVER !\n");
		return 1;
	}
	
	if(iolib_init())
	{
		printf("FAILED TO START BBBio !\n");
		return 1;
	}
	
	iolib_setdir(8,12, BBBIO_DIR_OUT);
	iolib_setdir(8,13, BBBIO_DIR_OUT);

	
	LedDriver ledDriver;


	ConnectionServeur
	
	
	while(1)
	{
		char * message;
		if(ConnectionServeur::verifRecevoirPret())
		{
			message = ConnectionServeur::recevoir();
			if(strcmp(message, "AllumerLumieresAlarme") == 0)
			{
				ledDriver.emergencyFlash();
			}
			else if(strcmp(message, "LumiereMontrerMed") == 0)
			{
				int id;
				if(sscanf(message,"LumiereMontrerMed%d",&id) != 1)
				{
					printf("BROKEN SPRINTF !\n");
				}
				ledDriver.pointTo(id);
			}
			else if(strcmp(message, "LEDOn") == 0)
			{
				ledDriver.ledOn();
			}
			else if(strcmp(message, "LEDOff") == 0)
			{
				ledDriver.ledOff();
			}
			else
			{
				printf("WARINING /!\\ Unknown request !\n");
			}
		}
		usleep(1000);
	}
	
	return 0;
}