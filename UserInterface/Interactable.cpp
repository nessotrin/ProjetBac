#include "Interactable.h"

Interactable::Interactable(Pos newPos, Size newSize, InteractMode newAllowedInteractMode, unsigned char newZHeight) : Renderable(newZHeight)
{
	pos = newPos;
	size = newSize;
	allowedInteractMode = newAllowedInteractMode;
}

void  Interactable::updatePos(Pos newPos) //overload to trigger extra action
{
	pos = newPos;
}