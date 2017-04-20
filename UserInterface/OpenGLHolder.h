#ifndef _OPENGL_HOLDER_H_
#define _OPENGL_HOLDER_H_

#include <SDL2/SDL.h>

#define WINDOW_SIZE_X 640
#define WINDOW_SIZE_Y 480

class OpenGLHolder
{
public:

	bool initGraphics();

	void beginFrame();
	void finishFrame();

private:

	SDL_Window * window;
	SDL_GLContext openGLContext;

};

#endif // _OPENGL_HOLDER_H_
