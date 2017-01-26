#ifndef _MODULE_INFO_H_
#define _MODULE_INFO_H_

/***
Structure qui définie les informations d'identification qu'un programme donnera au serveur
***/
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