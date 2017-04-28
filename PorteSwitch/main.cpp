#include <iostream>

#include <ConnectionServeur.h>

#include <BBBiolib.h>

#include <unistd.h>

#include <cstring>

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

			if(memcmp(message, "RecupEtatPorte",strlen("RecupEtatPorte")) == 0)
			{
				printf("Demade ...\n");
				if(!is_high(8,8))
				{
					printf("Porte ouverte\n");
					ConnectionServeur::envoyer("PorteOuverte\n");
				}
				else
				{
					printf("Porte fermee\n");
					ConnectionServeur::envoyer("PorteFermee\n");					
				}
				printf("Repondu\n");
			}
			else
			{
				printf("Requete inconnue\n");
			}
		}
		usleep(10000);
	}

    return 0;
}
