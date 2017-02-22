#ifndef _HUMAN_HANDLER_H_
#define _HUMAN_HANDLER_H_

#include <Human.h>

class HumanHandler
{
public:

	HumanHandler();

	int getHumanCount();
	bool iterateOnHumans(Human ** humandToUse);
	Human * getHuman(int id);
	
	void addHuman(Human * newMed);

private:
	Human ** humanList;
	int humanCount;
	int iteratorCounter;

};

#endif // _HUMAN_HANDLER_H_
