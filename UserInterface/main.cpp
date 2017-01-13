#include <iostream>

#include <ConnectionServeur.h>

#include <cstdio>
#include <unistd.h>

int main(int argc, char **argv)
{
    std::cout << "User interface" << std::endl;
	
	printf("%d\n",ConnectionServeur::initialisation("127.0.0.1",Ecran,0,0,1,true));
	
	
	char message[1024];
	sprintf(message,"ListerMedicaments\n");
	if(ConnectionServeur::envoyer(message))
	{
		return 1;
	}
	
	sleep(3);
	
	ConnectionServeur::fermer();
	
    return 0;
}
