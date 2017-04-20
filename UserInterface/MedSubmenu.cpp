#include "MedSubmenu.h"

#include "GlobalTexture.h"

#include "GLHelper.h"

MedSubmenu::MedSubmenu(Compositor * newCompositor, InputMaster * newInputMaster, List<Menu> * newMenuList, ScrollableTable * newScrollableTable, Pos newPos) : Menu(newCompositor, newInputMaster, newMenuList)
{
	scrollableTable = newScrollableTable;
	size = Size(50,50);
	pos = newPos;
}


void MedSubmenu::unselect()
{
	isSelected = false;
}

bool MedSubmenu::isDone()
{
	return false;
}

void MedSubmenu::work()
{
	
}

void MedSubmenu::init()
{
	buttonPlus = new Button(this,0,pos+Pos(0,0),Size(20,20),GlobalTexture::plusTexture,ZHeight+1);
	buttonMinus = new Button(this,1,pos+Pos(0,0),Size(20,20),GlobalTexture::minusTexture,ZHeight+1);
	compositor->addRenderable(buttonPlus);
	compositor->addRenderable(buttonMinus);
	inputMaster->addInteractable(buttonPlus);
	inputMaster->addInteractable(buttonMinus);
}

void MedSubmenu::deinit()
{
	compositor->removeRenderable(buttonPlus);
	compositor->removeRenderable(buttonMinus);
	inputMaster->removeInteractable(buttonPlus);
	inputMaster->removeInteractable(buttonMinus);
	free(buttonPlus);
	free(buttonMinus);
}

void MedSubmenu::render(Pos pos)
{
	unsigned char color[4];
	if(!isSelected)
	{
		color[0] = 240;		
		color[1] = 200;
		color[2] = 200;
	}
	else
	{
		color[0] = 200;		
		color[1] = 200;
		color[2] = 50;
	}
	color[3] = 255;
	GLHelper::drawColorSquare(pos,size,color,0,0,0);
}

void MedSubmenu::interact(Pos pos, InteractMode currentInteractMode, bool isRepeated)
{
	isSelected = true;
}

void MedSubmenu::callback(int id)
{
	if(id == 0)
	{
		printf("ADD");		
	}
	else
	{
		printf("REMOVE");		
	}
}