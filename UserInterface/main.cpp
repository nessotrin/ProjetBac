#include <iostream>

#include <ConnectionServeur.h>

#include <cstdio>
#include <unistd.h>
#include <cstdlib>
#include <cstring>

Medicament * recupererListeMedicament()
{
	char message[1024];
	sprintf(message,"ListerMedicaments\n");
	if(ConnectionServeur::envoyer(message))
	{
		return NULL;
	}
	
	char * reponse = ConnectionServeur::recevoir();
	if(reponse == NULL)
	{
		return NULL;
	}
	int nombreDeMed;
	if(sscanf(reponse,"Nombre%d\n",&nombreDeMed) == EOF)
	{
		printf("SSCANF ERROR\n");
		return NULL;
	}
	free(reponse);

	printf("%d Médicaments\n",nombreDeMed);
	
	Medicament * listeMeds = (Medicament *) malloc(sizeof(Medicament)*nombreDeMed);
	if(listeMeds == NULL)
	{
		printf("FAILED TO ALLOCATE\n");
		return NULL;
	}
		
	
	for(int i = 0 ; i < nombreDeMed ; i++)
	{
		reponse = ConnectionServeur::recevoir();
		if(reponse == NULL)
		{
			return NULL;
		}
		reponse[strlen(reponse)-1] = 0; // retirer le \n
		listeMeds->nom = reponse;
		reponse = ConnectionServeur::recevoir();
		if(reponse == NULL)
		{
			return NULL;
		}
		
		sscanf(reponse,"PoidBase%d Unite%d Compte%d Max%d Position%d\n",&listeMeds->poidDeBase,&listeMeds->poidUnite,&listeMeds->compte, &listeMeds->maximum,&listeMeds->position);
		free(reponse);
	}
	
	return listeMeds;
}

int main(int argc, char **argv)
{
    std::cout << "User interface" << std::endl;
	
	printf("%d\n",ConnectionServeur::initialisation("127.0.0.1",Ecran,0,0,1,true));
	
	
	Medicament * listeMeds = recupererListeMedicament();
	if(listeMeds == NULL)
	{
		return 1;
	}

	
	sleep(3);
	
	ConnectionServeur::fermer();
	
    return 0;
}
