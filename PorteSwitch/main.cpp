#include <iostream>

#include <ConnectionServeur.h>

#include <BBBiolib.h>

#include <unistd.h>

int main(int argc, char **argv)
{
	if( iolib_init() != 0)
	{
		printf("ERROR POIREAU\n");
	}

	iolib_setdir(8,8, BBBIO_DIR_IN);


	if(ConnectionServeur::initialisation("127.0.0.1", SwitchPorte, 1,0,0, 1))
	{
		printf("ERROR CAROTTE\n");
		return 1;
	}
	
	bool etatporte;
	
	while(true)
	{
		if(ConnectionServeur::verifRecevoirPret())
		{
			char * message = ConnectionServeur::recevoir();

			if(strcmp(message, "RecupererEtatPorte") == 0)
			{
				if(is_high(8,8))
				{
					ConnectionServeur::envoyer("PorteOuverte");
				}
				else
				{
					ConnectionServeur::envoyer("PorteFermee");					
				}
			}
		}
		usleep(10000);
	}

    return 0;
}
