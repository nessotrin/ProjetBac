#ifndef _MED_H_
#define _MED_H_


/***
Classe objet repésentant un médicament, elle stock son nom, son image et les autres caractéristiques typiques
Elle ne fait que stocker les valeurs de donner des accesseurs
***/
class Med
{
public:
	
Med(char * newName);

char * getName();

char * getImg();
void setImg(char * newImg);

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
	char * img;
	int baseWeigth;
	int unitWeigth;
	int currentCount;
	int maxCount;
	int location;
};

#endif // _MED_H_
