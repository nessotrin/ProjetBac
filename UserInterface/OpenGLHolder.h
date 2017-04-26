#ifndef _OPENGL_HOLDER_H_
#define _OPENGL_HOLDER_H_

#ifndef BBB

#include <SDL2/SDL.h>

#else

#include <GLES/egl.h>
	
#endif

#define WINDOW_SIZE_X 640
#define WINDOW_SIZE_Y 480

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

	
	
#endif

};

#endif // _OPENGL_HOLDER_H_
