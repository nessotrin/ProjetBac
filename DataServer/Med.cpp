#include "Med.h"

#include <cstring>

Med::Med(char * newName)
{
	name = newName;
}

char * Med::getName()
{
	return name;
}


char * Med::getImg()
{
	return img;
}
void Med::setImg(char * newImg)
{
	img = newImg;
}


int Med::getBaseWeigth()
{
	return baseWeigth;
}
void Med::setBaseWeigth(int newBaseWeigth)
{
	baseWeigth = newBaseWeigth;
}

int Med::getUnitWeigth()
{
	return unitWeigth;
}

void Med::setUnitWeigth(int newUnitWeigth)
{
	
}

int Med::getCurrentCount()
{
	return currentCount;
}
void Med::setCurrentCount(int newCurrentCount)
{
	currentCount = newCurrentCount;
}

int Med::getMaxCount()
{
	return maxCount;
}
void Med::setMaxCount(int newMaxCount)
{
	maxCount = newMaxCount;
}

int Med::getLocation()
{
	return location;
}
void Med::setLocation(int newLocation)
{
	location = newLocation;
}

