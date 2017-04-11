#ifndef _OPENGL_HOLDER_H_
#define _OPENGL_HOLDER_H_

#include <SDL2/SDL.h>


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
