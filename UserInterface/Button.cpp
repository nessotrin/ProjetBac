#include "Button.h"

#include <GL/gl.h>

#include <cstdio>

#include "GLHelper.h"

Button::Button(Callbackable * newCallbackObject, int newCallbackValue, Pos newPos , Size newSize, Texture newTexture, unsigned char newZHeight)
{
	callbackObject = newCallbackObject;
	callbackValue = newCallbackValue;
	pos = newPos;
	size = newSize;
	texture = newTexture;

	ZHeight = newZHeight;
	angle = 0;
	
	allowedInteractMode = InteractClick;

	printf("Button init'ed ...\n");	
}

void Button::interact(Pos pos, InteractMode currentInteractMode, bool isRepeated)
{
	callbackObject->callback(callbackValue);
}

extern Texture tex;

void Button::render(Pos offset)
{

	angle++;
	if(angle >= 360 || angle < 0)
	{
		angle = 0;
	}
	
	Pos p = pos+offset;
	
	//unsigned char color[] = {255,100,100,255};
	
	

//		GLHelper::drawTexturedSquare(Pos(0,0),Size(10,10),texture.GLtexture,0,0,0);

	GLHelper::drawTexturedSquare(pos+offset, size, texture.GLtexture, 0, angle, 0);
	//GLHelper::drawColorSquare(pos+offset, size, color, 0, 0, 0);

}