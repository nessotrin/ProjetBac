#ifndef _RENDERABLE_H_
#define _RENDERABLE_H_

#include "UIHelper.h"

class Renderable
{
public:
	Renderable(Pos newPos, Size newSize, unsigned char newZHeight);

	Pos pos;
	Size size;

	virtual void render(Pos offset) = 0;
	unsigned char ZHeight;
};

#endif // _RENDERABLE_H_
