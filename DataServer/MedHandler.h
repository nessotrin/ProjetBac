#ifndef _MEDHANDLER_H_
#define _MEDHANDLER_H_

#include "Med.h"

/***
Class handler qui gère les médicaments et leur stock
***/

class MedHandler
{
public:
	MedHandler();
	int getMedCount();
	bool iterateOnMeds(Med ** medToUse);
	Med * getMed(int id);
	
	void addMed(Med * newMed);

private:
	Med ** medList;
	int medCount;
	int iteratorCounter;
};

#endif // _MEDHANDLER_H_
