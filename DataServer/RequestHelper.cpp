#include "RequestHelper.h"

#include "Logger.h"

#include <cstring>


int RequestHelper::getOneIntArg(char * request, int requestCmdLength)
{	
	printf("HELPER--- \"%s\" searching at %d \n",request,requestCmdLength);
	if(strlen(request) <= requestCmdLength)
	{
		Logger::log("NO ARG APPENDED ON : \"%s\" !!",WarningLog,request);
		return 0;
	}

	Logger::log("Has a value, \"%s\"\n",InfoLog,request+requestCmdLength);

	int value;	
	if(sscanf(request+requestCmdLength,"%d\n",&value) == 0)
	{
		Logger::log("VALUE IS NOT A NUMBER ??!!\n",WarningLog);
	}

	Logger::log("Read the value %d\n",InfoLog,value);


		
	return value;
}
