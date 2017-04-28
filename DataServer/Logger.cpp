#include "Logger.h"

#define LOG_TO_CONSOLE 0x1
#define LOG_TO_LOGGERS 0x2
#define LOG_TO_FILE 0x4

#include <cstring>

FILE * Logger::logFile;
int Logger::logMode;

char * logLevelPrefix[] = { "[INFO]: ",
							"[WARNING]: ",
							"[ERROR]: ",
							"[VERSION]: ",
							"[REMOTE]: ",
							"[SPECIAL] ()()\n(\'.\')\n(\")(\")"};

void Logger::initLogger()
{
	logMode = LOG_TO_CONSOLE + LOG_TO_LOGGERS + LOG_TO_FILE;
	logFile = NULL;
}

bool Logger::initFile(char * filename)
{
	logFile = fopen(filename,"w+");
	if(logFile == NULL)
	{
		log("Logger: fopen \"%s\" failed with %d\n",ErrorLog,filename,logFile);
		return true;
	}
	
	return false;
}

void Logger::closeFile()
{
	fclose(logFile);
}

void Logger::log(const char* format, LogLevel logLevel, ...)
{ 
	va_list args;
	if(logMode & LOG_TO_CONSOLE)
	{
		char buffer[1024];
		int size = sprintf(buffer,"%s",logLevelPrefix[logLevel]);
		va_start (args, format);
		vsprintf (buffer+size,format, args);
		printfColored(buffer);
	}

	

	if(logMode & LOG_TO_LOGGERS)
	{
	/* send to loggers here */
	//		va_start (args, format);
	//		vsprintf (buffer, format, args);  
	}
	if(logMode & LOG_TO_FILE && logFile != NULL)
	{
		va_start (args, format);
		fprintf (logFile, "%s",logLevelPrefix[logLevel]); 
		vfprintf (logFile, format, args); 
		fflush(logFile);
	}

	va_end (args);
}

void Logger::setToConsole(bool value)
{
	if(value)
	{
		logMode |= LOG_TO_CONSOLE;
	}
	else
	{
		logMode &= ~LOG_TO_CONSOLE;
	}
}

void Logger::setToLoggers(bool value)
{
	if(value)
	{
		logMode |= LOG_TO_LOGGERS;
	}
	else
	{
		logMode &= ~LOG_TO_LOGGERS;
	}
}

void Logger::setToFile(bool value)
{
	if(value)
	{
		logMode |= LOG_TO_FILE;
	}
	else
	{
		logMode &= ~LOG_TO_FILE;
	}
}

void Logger::printfColored(char * buffer)
{	
	if(strstr(buffer, "[SPECIAL]") != NULL)
	{
		printf("\033[1;36m");
	}
	else if(strstr(buffer, "[ERROR]") != NULL)
	{
		printf("\033[1;31m");
	}
	else if(strstr(buffer, "[REMOTE]") != NULL)
	{
		printf("\033[1;39m");
	}
	else if(strstr(buffer, "[INFO]") != NULL)
	{
		printf("\033[1;39m");
	}
	else if(strstr(buffer, "[WARNING]") != NULL)
	{
		printf("\033[1;33m");
	}
	else if(strstr(buffer, "[VERSION]") != NULL)
	{
		printf("\033[1;32m");
	}
	else
	{
		printf("\033[1;30m");
	}
	
	printf("%s",buffer);
	
	printf("\033[0m\n");
}