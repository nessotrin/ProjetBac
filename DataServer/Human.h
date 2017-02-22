#ifndef _HUMAN_H_
#define _HUMAN_H_

class Human
{
public:
	Human(char * newName);
	
	char * getName();

	char * getImg();
	char * setImg(char * newImg);

	char * getAllowedMeds();
	void setAllowed(char * newAllowedMeds);
	
private:
	char * name;
	char * img;
	char * allowedMeds;
};

#endif // _HUMAN_H_
