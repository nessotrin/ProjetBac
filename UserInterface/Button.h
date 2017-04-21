#ifndef _BUTTON_H_
#define _BUTTON_H_

#include "Interactable.h"

#include "Callbackable.h"

#include "Texture.h"

class Button : public Interactable
{
public:
	Button(Pos newPos , Size newSize, unsigned char newZHeight, Callbackable * newCallbackObject, int newCallbackValue, Texture newTextureInactive, Texture newTextureActive);
	void render(Pos pos);
	void interact(Pos pos, InteractMode currentInteractMode, bool isRepeated);
	void work();
	
private:

	Callbackable * callbackObject;
	int callbackValue;
	Texture textureInactive;
	Texture textureActive;

	int angle;

	int activeCountdown;

};

#endif // _BUTTON_H_
