#include "Renderable.h"

Renderable::Renderable(Pos newPos, Size newSize, unsigned char newZHeight, unsigned char newAlpha)
{
	pos = newPos;
	size = newSize;
	ZHeight = newZHeight;
	alpha = newAlpha;
}

void Renderable::setAlpha(unsigned char newAlpha)
{
	alpha = newAlpha;
}