#ifndef _INTERACTABLE_H_
#define _INTERACTABLE_H_

#include "Renderable.h"

#include "UIHelper.h"


enum InteractMode
{
	InteractClick = 0b01,
	InteractSwipe = 0b10,
	InteractAll   = 0b11, // 11 ->   le ET binaire réponds oui pour les deux modes précédents
};

class Interactable : public Renderable
{
public:
	virtual void interact(Pos pos, InteractMode currentInteractMode) = 0;

	Pos pos;
	Size size;
	
	InteractMode allowedInteractMode;

};

#endif // _INTERACTABLE_H_
