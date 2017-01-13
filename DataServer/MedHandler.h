#ifndef _MEDHANDLER_H_
#define _MEDHANDLER_H_

#include "Med.h"

class MedHandler
{
public:
	MedHandler();
	int getMedCount();
	bool iterateOnMeds(Med ** medToUse);


private:
	Med * medList;
	int medCount;
	int iteratorCounter;
};

#endif // _MEDHANDLER_H_
