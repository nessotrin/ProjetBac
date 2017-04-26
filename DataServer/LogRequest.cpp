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
		Logger::log("%s",RemoteLog,request+14);
	}
	
}