#include "Interactable.h"

Interactable::Interactable(Pos newPos, Size newSize, unsigned char newZHeight, InteractMode newAllowedInteractMode) : Renderable(newPos, newSize, newZHeight)
{
	allowedInteractMode = newAllowedInteractMode;
}

void  Interactable::updatePos(Pos newPos) //overload to trigger extra action
{
	pos = newPos;
}