#ifndef _COMPOSITOR_H_
#define _COMPOSITOR_H_

#include "Renderable.h"
#include <cstring>

class Compositor
{
public:
	void addRenderable(Renderable * newRenderable);
	void render();
	void removeRenderable(Renderable * oldRenderable);


private:

	List<Renderable> renderableList;
};

#endif // _COMPOSITOR_H_
