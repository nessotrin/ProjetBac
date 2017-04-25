#include "NetworkLogger.h"

#include "IOHelper.h"

#include <cstring>

void NetworkLogger::log(int clientSocket, char * message)
{
	int readPos = 0;
	while(message[readPos] != 0) //remove the end of message marks (safety)
	{
		if(message[readPos] == '\n')
		{
			message[readPos] = ' ';
		}
		readPos++;
	}

	message[readPos] = '\n'; //add one at the end (safety)
	message[readPos+1] = 0; 

	
	IOHelper::sendRequest(clientSocket,message);
	
}