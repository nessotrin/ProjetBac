#ifndef _OPENGL_HOLDER_H_
#define _OPENGL_HOLDER_H_

#ifndef BBB

#include <SDL2/SDL.h>

#else

#include <EGL/egl.h>
#include <GLES2/gl2.h>
	
#endif

#define WINDOW_SIZE_X 640
#define WINDOW_SIZE_Y 480

#ifdef BBB
	extern GLuint programObject;
#endif


class OpenGLHolder
{
public:

	bool initGraphics();

	void beginFrame();
	void finishFrame();

private:


#ifndef BBB

	SDL_Window * window;
	SDL_GLContext openGLContext;

#else

	EGLDisplay  eGLDisplay;
	EGLSurface eGLSurface;
		
#endif

};

#endif // _OPENGL_HOLDER_H_
