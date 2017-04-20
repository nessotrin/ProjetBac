#include "ScrollableTable.h"

#include "GLHelper.h"

#include "OpenGLHolder.h"

ScrollableTable::ScrollableTable(Compositor * newCompositor, InputMaster * newInputMaster, List<Menu> * newMenuList, int newElementPerLine, int newElementPerColumn,Size newElementSize, Size newElementMargin, unsigned char newBackgroundColor[4], int newZHeight, Pos newPos, Size newSize) : Menu(newCompositor, newInputMaster, newMenuList)
{
	allowedInteractMode = InteractAll;
	scrollPos = 0;
	lastInteractPos = Pos(-1,-1);
	elementPerLine = newElementPerLine;
	elementPerColumn = newElementPerColumn;
	elementSize = newElementSize;
	elementPerLine = newElementPerLine;
	
	memcpy(backgroundColor,newBackgroundColor,4);

	ZHeight = newZHeight;
	pos = newPos;
	size = newSize;
}

bool ScrollableTable::isDone()
{
	return false;
}

#include <unistd.h>//sleep


void ScrollableTable::render(Pos offset)
{
	GLHelper::drawColorSquare(pos+offset,size,backgroundColor,0,0,0);
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


void ScrollableTable::interact(Pos interactPos, InteractMode interactMode, bool isRepeated)
{
	printf("INTERACT\n");
	
	
	if(isRepeated) //wait for the initial reference before moving
	{
		scrollPos +=  lastInteractPos.y - interactPos.y;
	}
	
	printf("DIFF = %d\n",interactPos.x- lastInteractPos.x);
	printf("SCROLLPOS %d\n",scrollPos);
	
	if(scrollPos < 0)
	{
		scrollPos = 0;
	}
	int maxScrollPos = (elementSize.y*elementPerColumn)+(elementMargin.y*(elementPerColumn+1))-(WINDOW_SIZE_Y-pos.y);
	printf("MAXSCROLLPOS %d\n",maxScrollPos);
	if(maxScrollPos < 0)
	{
		maxScrollPos = 0;
	}
	
	if(scrollPos >= maxScrollPos)
	{
		scrollPos = maxScrollPos;
	}
	
	
	
	lastInteractPos = interactPos;
}

void ScrollableTable::add(Renderable * newRenderable)
{
	elementList.add(newRenderable);
	elementPerColumn = ceil(elementList.getCount()/(float) elementPerLine);
}
void ScrollableTable::remove(Renderable * oldRenderable)
{
	elementList.remove(oldRenderable);	
	elementPerColumn = ceil(elementList.getCount()/(float) elementPerLine);
}

void ScrollableTable::work()
{
	
}

void ScrollableTable::init()
{
	compositor->addRenderable(this);
	inputMaster->addInteractable(this);
}

void ScrollableTable::deinit()
{
	compositor->removeRenderable(this);	
	inputMaster->removeInteractable(this);
}
