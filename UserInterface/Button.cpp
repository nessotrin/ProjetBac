#include "Button.h"

#ifndef BBB
#include <GL/gl.h>
#else
#include <GLES2/gl2.h>
#endif

#include <cstdio>

#include "GLHelper.h"

Button::Button(Pos newPos , Size newSize, unsigned char newZHeight, unsigned char newAlpha, Callbackable * newCallbackObject, int newCallbackValue, Texture newTextureInactive, Texture newTextureActive, int newRepeatInitialDelay, int newRepeatDelay) : Interactable(newPos, newSize, newZHeight, newAlpha, InteractClick)
{
	callbackObject = newCallbackObject;
	callbackValue = newCallbackValue;
	textureInactive = newTextureInactive;
	textureActive = newTextureActive;

	repeatInitialDelay = newRepeatInitialDelay;
	repeatDelay = newRepeatDelay;

	angle = 0;
	
	activeCountdown = 0;
	
}

void Button::interact(Pos pos, InteractMode currentInteractMode, bool isRepeated)
{
	if(!isRepeated)
	{
		callbackObject->callback(callbackValue);
		repeatCount = 0;
	}
	else
	{
		repeatCount++;
		if(repeatCount > repeatInitialDelay && (repeatCount-repeatInitialDelay)%repeatDelay == 0)
		{
			callbackObject->callback(callbackValue);
		}
	}
	activeCountdown = 1;
}

void Button::work()
{
	if(activeCountdown)
	{
		activeCountdown--;
	}
}

void Button::render(Pos offset)
{
/*
	angle++;
	if(angle >= 360 || angle < 0)
	{
		angle = 0;
	}
*/

	Pos p = pos+offset;
	
	unsigned char color[] = {255,255,255,alpha};
	
	if(activeCountdown)
	{
		GLHelper::drawColoredTexturedSquare(pos+offset, size, color, textureActive.GLtexture, 0, angle, 0);
	}
	else
	{
		GLHelper::drawColoredTexturedSquare(pos+offset, size, color, textureInactive.GLtexture, 0, angle, 0);		
	}


}
