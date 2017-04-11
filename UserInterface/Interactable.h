#ifndef _INTERACTABLE_H_
#define _INTERACTABLE_H_

#include "Renderable.h"

#include "UIHelper.h"

class Interactable : public Renderable
{
public:
	virtual void interact(Pos pos) = 0;

	Pos pos;
	Size size;


};

#endif // _INTERACTABLE_H_
