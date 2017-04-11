#include "Compositor.h"
#include <cstdio>
#include <cstdlib>


void Compositor::addRenderable(Renderable * newRenderable)
{
	renderableList.add(newRenderable);
}

void Compositor::render()
{
	for(int ZHeight = 0 ; ZHeight <= 255 ; ZHeight++)
	{
		for(int i = 0 ; i < renderableList.getCount() ; i++)
		{
			if(renderableList.get(i)->ZHeight == ZHeight)
			{
				renderableList.get(i)->render();
			}
		}		
	}
}

void Compositor::removeRenderable(Renderable * oldRenderable)
{
	renderableList.remove(oldRenderable);
}