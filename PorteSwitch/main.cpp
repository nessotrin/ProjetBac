#include <iostream>

#include <ConnectionServeur.h>

#include <BBBiolib.h>

int main(int argc, char **argv)
{
	if( iolib_init() != 0)
	{
		printf("ERROR POIREAU\n");
	}

	if(ConnectionServeur::initialisation("127.0.0.1", switchPorte, 1,0,0, 1))
	{
		printf("ERROR CAROTTE\n");
		return 1;
	}
	
	bool etatporte;
	
	while(true)
	{
		bool porteactuelle = is_high(8,888);
		if(etatporte != porteactuelle)
		{
			etatporte = porteactuelle;
			if(etatporte == 1)
			{
				ConnectionServeur::envoyer("PorteFermee");
			}
			else
			{
				ConnectionServeur::envoyer("PorteOuverte");
			}
		}
	}

    return 0;
}
