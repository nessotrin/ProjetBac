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
	

	printf("Binding texture ...\n");

	glEnable(GL_TEXTURE_2D);
	GLHelper::CheckForErrors("Enable texture");
	glBindTexture(GL_TEXTURE_2D, texture->GLtexture);
	GLHelper::CheckForErrors("Bind texture");

	printf("Button init'ed ...\n");	
}

void Button::interact(Pos pos, InteractMode currentInteractMode)
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
	
	float sizeX = size.x/(float)(640/2);
	float sizeY = size.y/(float)(480/2);
	
	float startX = -sizeX/2;
	float endX = sizeX/2;
	float startY = -sizeY/2;
	float endY = sizeY/2;
	
	
	float vertices[] = {0, 0,   0, 1,   1, 0};


	
	
	float translateX = ((pos.x+offset.x+size.x/2)-(640/2))/(float)(640/2);
	float translateY = -((pos.y+offset.y+size.y/2)-(480/2))/(float)(480/2);

	glTranslated(translateX,translateY,0);

    glRotated(angle,0,1,0);

	glBegin(GL_QUADS);
		glTexCoord2d(0,1); glVertex2d(startX,startY);

		glTexCoord2d(0,0); glVertex2d(startX,endY);

		glTexCoord2d(1,0); glVertex2d(endX,endY);

		glTexCoord2d(1,1); glVertex2d(endX,startY);
	glEnd();

}