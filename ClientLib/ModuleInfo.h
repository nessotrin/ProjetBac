#ifndef _MODULE_INFO_H_
#define _MODULE_INFO_H_

struct ModuleInfo
{
	int type;
	int versionMajor;
	int versionMinor;
	int versionPatch;
	bool isDebug;
};

typedef ModuleInfo ModuleInfo;

#endif // _MODULE_INFO_H_