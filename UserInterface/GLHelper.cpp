#include "GLHelper.h"

#include <GL/glut.h>

#include <cstdio>

void GLHelper::CheckForErrors(char * text)
{
	GLenum err;
    while ( (err = glGetError()) != GL_NO_ERROR)
	{
        printf("OpenGL error: %x in \"%s\" \n", err,text);
    }
}

void GLHelper::drawTexturedSquare(Pos pos, Size size, GLint texture, int angleX, int angleY, int angleZ)
{	
	float sizeX = size.x/(float)(640/2);
	float sizeY = size.y/(float)(480/2);
	
	float startX = -sizeX/2;
	float endX = sizeX/2;
	float startY = -sizeY/2;
	float endY = sizeY/2;
	
	
	float translateX = ((pos.x+size.x/2)-(640/2))/(float)(640/2);
	float translateY = -((pos.y+size.y/2)-(480/2))/(float)(480/2);

	glEnable(GL_TEXTURE_2D);
	GLHelper::CheckForErrors("Enable texture");
	glBindTexture(GL_TEXTURE_2D, texture);
	GLHelper::CheckForErrors("Bind texture");

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);


//    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity( );

	glTranslated(translateX,translateY,0);

    glRotated(angleX+angleY+angleZ,angleX,angleY,angleZ);

	glBegin(GL_QUADS);
		glTexCoord2d(0,1); glVertex2d(startX,startY);

		glTexCoord2d(0,0); glVertex2d(startX,endY);

		glTexCoord2d(1,0); glVertex2d(endX,endY);

		glTexCoord2d(1,1); glVertex2d(endX,startY);
	glEnd();


}

void GLHelper::drawColorSquare(Pos pos, Size size, unsigned char color[4], int angleX, int angleY, int angleZ)
{	
	float sizeX = size.x/(float)(640/2);
	float sizeY = size.y/(float)(480/2);
	
	float startX = -sizeX/2;
	float endX = sizeX/2;
	float startY = -sizeY/2;
	float endY = sizeY/2;
	
	
	float translateX = ((pos.x+size.x/2)-(640/2))/(float)(640/2);
	float translateY = -((pos.y+size.y/2)-(480/2))/(float)(480/2);

	glDisable(GL_TEXTURE_2D);
	GLHelper::CheckForErrors("Disable texture");


    glLoadIdentity( );

	glTranslated(translateX,translateY,0);

    glRotated(angleX+angleY+angleZ,angleX,angleY,angleZ);

	glBegin(GL_QUADS);
		glColor4ub(color[0],color[1],color[2],color[3]);
		
		glVertex2d(startX,startY);

		glVertex2d(startX,endY);

		glVertex2d(endX,endY);

		glVertex2d(endX,startY);
	glEnd();


}