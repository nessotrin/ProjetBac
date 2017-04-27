#ifndef _GL_HELPER_H_
#define _GL_HELPER_H_

#include "UIHelper.h"

#include "OpenGLHolder.h"

#ifndef BBB
#include <GL/gl.h>
#else
#include <GLES2/gl2.h>
#endif


class GLHelper
{
public:
	static void CheckForErrors(char * text);
	static void drawTexturedSquare(Pos pos, Size size, GLuint texture, int angleX, int angleY, int angleZ);
	static void drawColoredTexturedSquare(Pos pos, Size size,unsigned char color[4], GLuint texture, int angleX, int angleY, int angleZ);
	static void drawColorSquare(Pos pos, Size size, unsigned char color[4], int angleX, int angleY, int angleZ);
	static void alphaOnRGBA(unsigned char * color, unsigned char alpha);
private:
	static void drawSetPos(Pos pos, Size size, float * startX, float * endX, float * startY, float * endY, int angleX, int angleY, int angleZ);

};

#endif // _GL_HELPER_H_
