#ifndef _BUTTON_H_
#define _BUTTON_H_

#include "Interactable.h"

#include "Callbackable.h"

#include "Texture.h"

class Button : public Interactable
{
public:
	Button(Pos newPos , Size newSize, unsigned char newZHeight, unsigned char newAlpha, Callbackable * newCallbackObject, int newCallbackValue, Texture newTextureInactive, Texture newTextureActive, int newRepeatInitialDelay, int newRepeatDelay);
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

	int repeatInitialDelay;
	int repeatDelay;
	
	int repeatCount;

};

#endif // _BUTTON_H_
