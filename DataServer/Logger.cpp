#include "Logger.h"

#define LOG_TO_CONSOLE 0x1
#define LOG_TO_LOGGERS 0x2
#define LOG_TO_FILE 0x4

FILE * Logger::logFile;
int Logger::logMode;

char * logLevelPrefix[] = { "[INFO]: ",
							"[WARNING]: ",
							"[  ERROR  ]: ",
							"[VERSION]: ",
							"[REMOTE]: ",
							"()()\n(\'.\')\n(\")(\")"};

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
		printf("%s",logLevelPrefix[logLevel]);
		va_start (args, format);
		vprintf (format, args);
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