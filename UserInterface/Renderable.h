#ifndef _RENDERABLE_H_
#define _RENDERABLE_H_

#include "UIHelper.h"

class Renderable
{
public:
	virtual void render(Pos pos) = 0;
	unsigned char ZHeight;
};

#endif // _RENDERABLE_H_
