#include "Button.h"

#include <GL/gl.h>

#include <cstdio>

#include "GLHelper.h"

Button::Button(Callbackable * newCallbackObject, int newCallbackValue, Pos newPos , Size newSize, Texture * newTexture, unsigned char newZHeight)
{
	callbackObject = newCallbackObject;
	callbackValue = newCallbackValue;
	pos = newPos;
	size = newSize;
	texture = newTexture;
	ZHeight = newZHeight;
	angle = 0;
	
	allowedInteractMode = InteractClick;

	printf("Binding texture ...\n");

	glEnable(GL_TEXTURE_2D);
	GLHelper::CheckForErrors("Enable texture");
	glBindTexture(GL_TEXTURE_2D, texture->GLtexture);
	GLHelper::CheckForErrors("Bind texture");

	printf("Button init'ed ...\n");	
}

void Button::interact(Pos pos, InteractMode currentInteractMode, bool isRepeated)
{
	callbackObject->callback(callbackValue);
}


void Button::render(Pos offset)
{

	angle++;
	if(angle >= 360 || angle < 0)
	{
		angle = 0;
	}
	
	Pos p = pos+offset;
	
	GLHelper::drawTexturedSquare(pos+offset, size, texture->GLtexture, 0, angle, 0);

}