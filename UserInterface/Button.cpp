#include "Button.h"

#include <GL/gl.h>

#include <cstdio>

#include "GLHelper.h"

Button::Button(Pos newPos , Size newSize, unsigned char newZHeight, Callbackable * newCallbackObject, int newCallbackValue, Texture newTextureInactive, Texture newTextureActive) : Interactable(newPos, newSize, InteractClick, newZHeight)
{
	callbackObject = newCallbackObject;
	callbackValue = newCallbackValue;
	textureInactive = newTextureInactive;
	textureActive = newTextureActive;

	angle = 0;
	
	activeCountdown = 0;
	
}

void Button::interact(Pos pos, InteractMode currentInteractMode, bool isRepeated)
{
	callbackObject->callback(callbackValue);
	activeCountdown = 10;
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
	
	unsigned char color[] = {255,100,100,255};
	
	

	//	GLHelper::drawTexturedSquare(Pos(0,0),Size(10,10),texture.GLtexture,0,0,0);

//	GLHelper::drawColorSquare(pos+offset, size, color, 0, 0, 0);

	
	if(activeCountdown)
	{
		GLHelper::drawTexturedSquare(pos+offset, size, textureActive.GLtexture, 0, angle, 0);
	}
	else
	{
		GLHelper::drawTexturedSquare(pos+offset, size, textureInactive.GLtexture, 0, angle, 0);		
	}


}