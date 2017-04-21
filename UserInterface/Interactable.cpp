#include "Interactable.h"

Interactable::Interactable(Pos newPos, Size newSize, unsigned char newZHeight, unsigned char newAlpha, InteractMode newAllowedInteractMode) : Renderable(newPos, newSize, newZHeight, newAlpha)
{
	allowedInteractMode = newAllowedInteractMode;
}

void  Interactable::updatePos(Pos newPos) //overload to trigger extra action
{
	pos = newPos;
}