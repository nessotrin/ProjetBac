#include "NetworkLogger.h"

#include "IOHelper.h"

#include <cstring>

void NetworkLogger::log(int clientSocket, char * message)
{
	int readPos = 0;
	while(message[readPos] != 0) //replace '\n' (end of message mark) by 0x6 during transport 
	{
		if(message[readPos] == '\n')
		{
			message[readPos] = 0x6;// ASCII ACK -> Espace vide
		}
		readPos++;
	}

	message[readPos] = '\n'; //add one at the end (safety)
	message[readPos+1] = 0; 

	
	IOHelper::sendRequest(clientSocket,message);
}