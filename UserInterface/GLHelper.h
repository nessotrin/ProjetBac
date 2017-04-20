#ifndef _GL_HELPER_H_
#define _GL_HELPER_H_

#include "UIHelper.h"

#include <GL/gl.h>


class GLHelper
{
public:
	static void CheckForErrors(char * text);
	static void drawTexturedSquare(Pos pos, Size size, GLuint texture, int angleX, int angleY, int angleZ);
	static void drawColorSquare(Pos pos, Size size, unsigned char color[4], int angleX, int angleY, int angleZ);
};

#endif // _GL_HELPER_H_
