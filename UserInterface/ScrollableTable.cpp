#include "ScrollableTable.h"

#include "GLHelper.h"

ScrollableTable::ScrollableTable(Compositor * newCompositor, InputMaster * newInputMaster, List<Menu> * newMenuList, int newElementPerLine, int newElementPerColumn,Size newElementSize, Size newElementMargin, unsigned char newBackgroundColor[4]) : Menu(newCompositor, newInputMaster, newMenuList)
{
	allowedInteractMode = InteractSwipe;
	scrollPos = 0;
	lastInteractPos = Pos(-1,-1);
	elementPerLine = newElementPerLine;
	elementPerColumn = newElementPerColumn;
	elementSize = newElementSize;
	elementPerLine = newElementPerLine;
	
	memcpy(backgroundColor,newBackgroundColor,4);
}

bool ScrollableTable::isDone()
{
	return false;
}

void ScrollableTable::render(Pos pos)
{
	GLHelper::drawColorSquare(tablePos+pos,tableSize,backgroundColor);
	int cellX = 0;
	int cellY = 0;
	for(int i = 0 ; i < elementList.getCount() ; i++)
	{
		if(cellX == elementPerLine)
		{
			cellX = 0;
			cellY++;
		}
			
		Pos renderPos(elementMargin.x + (elementMargin.x+elementSize.x)*cellX,
					  elementMargin.y + (elementMargin.y+elementSize.y)*cellY - scrollPos);
		
		elementList.get(i)->render(renderPos+pos);
			
		cellX++;
	}
}


void ScrollableTable::interact(Pos pos, InteractMode interactMode)
{
	scrollPos += pos.x - lastInteractPos.x;
	
	if(scrollPos < 0)
	{
		scrollPos = 0;
	}
	int maxScrollPos = (elementSize.y*elementPerColumn)+(elementMargin.y*(elementPerColumn+1))-tableSize.y;
	if(scrollPos >= maxScrollPos)
	{
		scrollPos = maxScrollPos;
	}
	
	
	
	lastInteractPos = pos;
}

void ScrollableTable::add(Renderable * newRenderable)
{
	elementList.add(newRenderable);
}
void ScrollableTable::remove(Renderable * oldRenderable)
{
	elementList.remove(oldRenderable);	
}

void ScrollableTable::work()
{
	
}

void ScrollableTable::init()
{
	
}

void ScrollableTable::deinit()
{
	
}
