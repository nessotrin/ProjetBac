#include <iostream>

#include <ConnectionServeur.h>

#include <cstdio>

int main(int argc, char **argv)
{
    std::cout << "User interface" << std::endl;
	
	printf("%d\n",ConnectionServeur::initialisation("127.0.0.1",Ecran,0,0,1,true));
	
    return 0;
}
