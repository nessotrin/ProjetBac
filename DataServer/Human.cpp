#include "Human.h"

Human::Human(char * newName)
{
	name = newName;
}
	
char * Human::getName()
{
	return name;
}
char * Human::getAllowedMeds()
{
	return allowedMeds;
}
void Human::setAllowed(char * newAllowedMeds)
{
	allowedMeds = newAllowedMeds;
}
