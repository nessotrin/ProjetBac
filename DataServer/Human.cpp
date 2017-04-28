#include "Human.h"

Human::Human(char * newName)
{
	name = newName;
}
	
char * Human::getName()
{
	return name;
}
char * Human::getImg()
{
	return img;
}
void Human::setImg(char * newImg)
{
	img = newImg;
}


char * Human::getAllowedMeds()
{
	return allowedMeds;
}
void Human::setAllowed(char * newAllowedMeds)
{
	allowedMeds = newAllowedMeds;
}
