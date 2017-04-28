#ifndef _HUMAN_H_
#define _HUMAN_H_


/***
Class objet qui représente un humain, elle stock son nom, son image et ses permissions
Elle ne fait que stocker les valeurs de donner des accesseurs
***/
class Human
{
public:
	Human(char * newName);
	
	char * getName();

	char * getImg();
	void setImg(char * newImg);

	char * getAllowedMeds();
	void setAllowed(char * newAllowedMeds);
	
private:
	char * name;
	char * img;
	char * allowedMeds;
};

#endif // _HUMAN_H_
