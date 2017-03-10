#include "RequestHelper.h"

#include "Logger.h"

#include <cstring>


int RequestHelper::getOneIntArg(char * request, int requestCmdLength)
{	
	printf("HELPER---\n");
	if(strlen(request) <= requestCmdLength)
	{
		Logger::log("NO ARG APPENDED ON : \"%s\" !!",request);
		return 0;
	}

	printf("Has a value\n");

	int value;	
	sscanf("%d",request+requestCmdLength,&value);

	printf("Read the value %d\n",value);


		
	return value;
}
