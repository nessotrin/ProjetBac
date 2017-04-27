#include "GLHelper.h"

#include <cstdio>

void GLHelper::CheckForErrors(char * text)
{
	GLenum err;
    while ( (err = glGetError()) != GL_NO_ERROR)
	{
        printf("OpenGL error: %x in \"%s\" \n", err,text);
    }
}

#include "Texture.h"

void GLHelper::drawSetPos(Pos pos, Size size, float * startX, float * endX, float * startY, float * endY, int angleX, int angleY, int angleZ)
{	
	float sizeX = size.x/(float)(640/2);
	float sizeY = size.y/(float)(480/2);
	
	float translateX = ((pos.x+size.x/2)-(640/2))/(float)(640/2);
	float translateY = -((pos.y+size.y/2)-(480/2))/(float)(480/2);


	*startX = -sizeX/2 + translateX;
	*endX = sizeX/2 + translateX;
	*startY = -sizeY/2 + translateY;
	*endY = sizeY/2 + translateY;
	
	


	#ifndef BBB

	glLoadIdentity();

//	glTranslated(translateX,translateY,0);

//    glRotated(angleX+angleY+angleZ,angleX,angleY,angleZ);
	
	#else

	glUseProgram(programObject);
    
	#endif	

}

#ifdef OPENGL2

void GLHelper::drawColoredTexturedSquare(Pos pos, Size size, unsigned char color[4], GLuint texture, int angleX, int angleY, int angleZ)
{	

	float startX, endX, startY, endY;

	drawSetPos(pos,size,&startX,&endX,&startY,&endY,angleX,angleY,angleZ);

	glEnable(GL_TEXTURE_2D);
	GLHelper::CheckForErrors("Enable texture");


	glBindTexture(GL_TEXTURE_2D, texture);
	GLHelper::CheckForErrors("Bind texture");

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	GLHelper::CheckForErrors("Enable Alpha");

	glEnable(GL_BLEND);
	GLHelper::CheckForErrors("Enable blend");

	glColor4ub(color[0],color[1],color[2],color[3]);

	glBegin(GL_QUADS);
		glTexCoord2d(0,1); glVertex2d(startX,startY);

		glTexCoord2d(0,0); glVertex2d(startX,endY);

		glTexCoord2d(1,0); glVertex2d(endX,endY);

		glTexCoord2d(1,1); glVertex2d(endX,startY);
	glEnd();


}

void GLHelper::drawTexturedSquare(Pos pos, Size size, GLuint texture, int angleX, int angleY, int angleZ)
{	
	unsigned char color[] = {255,255,255,255};
	drawColoredTexturedSquare(pos,size,color,texture,angleX,angleY,angleZ);
}


void GLHelper::drawColorSquare(Pos pos, Size size, unsigned char color[4], int angleX, int angleY, int angleZ)
{	
	float startX, endX, startY, endY;

	drawSetPos(pos,size,&startX,&endX,&startY,&endY,angleX,angleY,angleZ);

	glDisable(GL_TEXTURE_2D);
	GLHelper::CheckForErrors("Disable texture");

	glBegin(GL_QUADS);
		glColor4ub(color[0],color[1],color[2],color[3]);
		
		glVertex2d(startX,startY);

		glVertex2d(startX,endY);

		glVertex2d(endX,endY);

		glVertex2d(endX,startY);
	glEnd();


}

#else
void GLHelper::drawColoredTexturedSquare(Pos pos, Size size, unsigned char color[4], GLuint texture, int angleX, int angleY, int angleZ)
{	
	float sizeX = size.x/(float)(640/2);
	float sizeY = size.y/(float)(480/2);
	
	float translateX = ((pos.x+size.x/2)-(640/2))/(float)(640/2);
	float translateY = -((pos.y+size.y/2)-(480/2))/(float)(480/2);


	float startX = -sizeX/2 + translateX;
	float endX = sizeX/2 + translateX;
	float startY = -sizeY/2 + translateY;
	float endY = sizeY/2 + translateY;

	GLfloat position[] = {startX,startY,0,  startX,endY,0,  endX,startY,0,
						  endX,startY,0,    endX,endY,0,    startX,endY,0};
	GLfloat textureCoords[] = {0,1, 0,0, 1,0,
                                  1,1, 1,0, 0,0};


	glUseProgram(programObject);

	GLint mTextureUniformHandle = glGetUniformLocation(programObject, "u_Texture");
	GLint mPositionHandle = glGetAttribLocation(programObject, "a_Position");
	GLint mColorHandle = glGetAttribLocation(programObject, "a_Color");
	GLint mTextureCoordinateHandle = glGetAttribLocation(programObject, "a_TexCoordinate");

	// Set the active texture unit to texture unit 0.
	glActiveTexture(GL_TEXTURE0);

	// Bind the texture to this unit.
	glBindTexture(GL_TEXTURE_2D, texture);

	// Tell the texture uniform sampler to use this texture in the shader by binding to texture unit 0.
	glUniform1i(mTextureUniformHandle, 0); 

	glEnable(GL_TEXTURE_2D);
	GLHelper::CheckForErrors("Enable texture");
	
	glVertexAttribPointer(mPositionHandle, 6*3, GL_FLOAT, false, 0, position);        
	glEnableVertexAttribArray(mPositionHandle);        
        
	glVertexAttribPointer(mColorHandle, 1*4, GL_UNSIGNED_BYTE, false, 0, color);        
	glEnableVertexAttribArray(mColorHandle);
        
	glVertexAttribPointer(mTextureCoordinateHandle, 6*2, GL_FLOAT, false, 0, textureCoords);
	glEnableVertexAttribArray(mTextureCoordinateHandle);
        
	glDrawArrays(GL_TRIANGLES, 0, 6);
	
}

void GLHelper::drawTexturedSquare(Pos pos, Size size, GLuint texture, int angleX, int angleY, int angleZ)
{	
	unsigned char color[] = {255,255,255,255};
	drawColoredTexturedSquare(pos,size,color,texture,angleX,angleY,angleZ);
}


void GLHelper::drawColorSquare(Pos pos, Size size, unsigned char color[4], int angleX, int angleY, int angleZ)
{	
	/*
	float startX, endX, startY, endY;
	
	drawSetPos(pos,size,&startX,&endX,&startY,&endY,angleX,angleY,angleZ);
 
	glDisable(GL_TEXTURE_2D);
 
	GLfloat box[] = {startX,startY,0,  startX,endY,0,  endX,endY,0,   endX,startY,0};
 
	glColor4ub(color[0],color[1],color[2],color[3]);
		

	glEnableClientState(GL_VERTEX_ARRAY);
	GLHelper::CheckForErrors("Enable vertex");

	glVertexPointer(3, GL_FLOAT, 0,box);
 
	glDrawArrays(GL_QUADS,0,4);
 
	glDisableClientState(GL_VERTEX_ARRAY);
	*/
}
	

#endif //OPENGL2


void GLHelper::alphaOnRGBA(unsigned char * color, unsigned char alpha)
{
	color[3] = (int)(color[3]*(alpha/(float)255));
}
