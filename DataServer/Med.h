#ifndef _MED_H_
#define _MED_H_

class Med
{
public:
	
Med(char * newName);

int getBaseWeigth();
void setBaseWeigth(int newBaseWeigth);

int getUnitWeigth();
void setUnitWeigth(int newUnitWeigth);

int getCurrentCount();
void setCurrentCount(int newCurrentCount);

int getMaxCount();
void setMaxCount(int newMaxCount);

int getLocation();
void setLocation(int newLocation);
	
private:
	char * name;
	int baseWeigth;
	int unitWeigth;
	int currentCount;
	int maxCount;
	int location;
};

#endif // _MED_H_
