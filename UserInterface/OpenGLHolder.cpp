#include "OpenGLHolder.h"


#include <cstdio>

#include <GL/gl.h>



bool OpenGLHolder::initGraphics()
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 0);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    window = SDL_CreateWindow("UserInterface - W.I.P.", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_SIZE_X, WINDOW_SIZE_Y, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    openGLContext = SDL_GL_CreateContext(window);
	if(openGLContext == 0)
	{
		printf("ERROR: Something's wrong with the window & opengl /!\\ \n");
		return true;
	}
	
	return false;
}

void OpenGLHolder::beginFrame()
{
	glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity( );

}

void OpenGLHolder::finishFrame()
{
	glFlush();
	SDL_GL_SwapWindow(window);
}
