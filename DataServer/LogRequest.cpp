#include "LogRequest.h"

#include "Logger.h"

#include <cstdio>
#include <cstring>

LogRequest::LogRequest(RequestHandler * requestHandler)
{
	requestHandler->addRequestEntry("LogSurServeur ",this);
}

void LogRequest::handleRequest(char * request, Client * client)
{
	printf("handleRequest with LOGREQUEST\n");
	
	if(strlen(request) >= 14 && memcmp(request, "LogSurServeur ", 14) == 0)
	{
		for(int i = 14 ; i < strlen(request) ; i++) //put back the '\n' in the message
		{
			if(request[i] == 0x6)
			{
				request[i] = '\n';
			}
		}
		Logger::log("%s",RemoteLog,request+14);
	}
	
}