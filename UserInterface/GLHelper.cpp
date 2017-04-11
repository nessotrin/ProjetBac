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
