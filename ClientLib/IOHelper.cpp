#include "IOHelper.h"

#include <unistd.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>

char * IOHelper::sendRequestAndGetRequest(int clientSocket, char * requestBuffer)
{
	if(sendRequest(clientSocket,requestBuffer))
	{
		return NULL;
	}
	
	return getRequest(clientSocket);
}
char * IOHelper::getRequest(int clientSocket)
{
	char * buffer = NULL;
	int bufferSize = 0;
	int bufferPos = 0;
	do
	{
		if(bufferPos == bufferSize)
		{
			bufferSize += 20;
			buffer = (char *) realloc(buffer, bufferSize);
			if(buffer == NULL)
			{
				printf("ALLOC ERROR !\n");
				return NULL;
			}
		}
		bufferPos += read(clientSocket, buffer+bufferPos, 1);
	} while(bufferPos == 0 || buffer[bufferPos-1] != '\n');
	
	return buffer;
}
bool IOHelper::sendRequest(int clientSocket, char * requestBuffer)
{
	int length = strlen(requestBuffer);
	int writePos = 0;
	while(writePos != length)
	{
		writePos += write(clientSocket, requestBuffer+writePos, length-writePos);
	}
	return false;
}

