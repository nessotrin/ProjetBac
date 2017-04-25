#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <stdio.h>
#include <stdarg.h>

enum LogLevel
{
	InfoLog = 0,
	WarningLog,
	ErrorLog,
	VersionLog,
	RemoteLog,
	SpecialLog,
};

class Logger
{
public:
	static void initLogger();
	static void log(const char * format, LogLevel level ...);
	static bool initFile(char* filename);
	static void closeFile();
	static void setToConsole(bool value);
	static void setToLoggers(bool value);
	static void setToFile(bool value);
	
private:
	static FILE * logFile;
	static int logMode;
};

#endif // _LOGGER_H_
