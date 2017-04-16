#include "RequestHelper.h"

#include "Logger.h"

#include <cstring>


int RequestHelper::getOneIntArg(char * request, int requestCmdLength)
{	
	printf("HELPER--- \"%s\" searching at %d \n",request,requestCmdLength);
	if(strlen(request) <= requestCmdLength)
	{
		Logger::log("NO ARG APPENDED ON : \"%s\" !!",request);
		return 0;
	}

	printf("Has a value, \"%s\"\n",request+requestCmdLength);

	int value;	
	if(sscanf(request+requestCmdLength,"%d\n",&value) == 0)
	{
		printf("VALUE IS NOT A NUMBER ??!!\n");
	}

	printf("Read the value %d\n",value);


		
	return value;
}
