#include <stdio.h>

void changerEtatAimant(bool statusPin)
{
	
}

int main(int argc, char **argv)
{
	printf("%d\n",ConnectionServeur::initialisation("127.0.0.1",VerrouPorte,0,0,1,true));
	
	while(1)
	{
		char * message = ConnectionServeur::recevoir();
		if(message != NULL)
		{
			if(strlen(message) >= 16 && memcmp(message,"OuvrirPorte",16) == 0)
			{
				printf("Ouverture porte !\n");
				ConnectionServeur::envoyer("RecupEtatPorte");
				char * reponse = ConnectionServeur::recevoir();
				bool porteFerme = true;
				while()
				if(strlen(message) >= 16 && memcmp(message,"OuvrirPorte",16) == 0)
			}
			else if(strlen(message) >= 16 && memcmp(message,"FermerPorte",16) == 0)
			{
				printf("Fermeture porte !\n");			
			}
			else
			{
				printf("ERROR: Unknown request \"%s\"\n",message);
			}
			free(message);
		}

	}
	
	return 0;
}
