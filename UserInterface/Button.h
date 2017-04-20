#ifndef _BUTTON_H_
#define _BUTTON_H_

#include "Interactable.h"

#include "Callbackable.h"

#include "Texture.h"

class Button : public Interactable
{
public:
	Button(Callbackable * newCallbackObject, int newCallbackValue, Pos newPos , Size newSize, Texture newTexture, unsigned char newZHeight);
	void render(Pos pos);
	void interact(Pos pos, InteractMode currentInteractMode, bool isRepeated);
	
private:

	Callbackable * callbackObject;
	int callbackValue;
	Texture texture;

	int angle;


};

#endif // _BUTTON_H_
