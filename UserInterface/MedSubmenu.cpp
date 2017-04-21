#include "MedSubmenu.h"

#include "GlobalTexture.h"

#include "GLHelper.h"

MedSubmenu::MedSubmenu(Pos newPos, Size newSize, int newZHeigt, Compositor * newCompositor, InputMaster * newInputMaster, List<Menu> * newMenuList, List<MedSubmenu> * newMedSubmenuList) : Menu(newCompositor, newInputMaster, newMenuList), Interactable(newPos,newSize,InteractClick,newZHeigt)
{
	medSubmenuList = newMedSubmenuList;
	
	isSelected = false;
	
	buttonPlus = NULL;
	buttonMinus = NULL;
	
}


void MedSubmenu::unselect()
{
	isSelected = false;
	removeButtons();
}

bool MedSubmenu::isDone()
{
	return false;
}

void MedSubmenu::work()
{
	buttonMinus->work();
	buttonPlus->work();
}

void MedSubmenu::init()
{
	buttonPlus = new Button(Pos(-1,-1), Size((size.x-6)/2,(size.y-6)/2), ZHeight+1, this, 0, GlobalTexture::plusTexture, GlobalTexture::plusTextureActive);
	buttonMinus = new Button(Pos(-1,-1), Size((size.x-6)/2,(size.y-6)/2), ZHeight+1, this, 0, GlobalTexture::minusTexture, GlobalTexture::minusTextureActive);
}

void MedSubmenu::addButtons()
{
	compositor->addRenderable(buttonPlus);
	compositor->addRenderable(buttonMinus);
	inputMaster->addInteractable(buttonPlus);
	inputMaster->addInteractable(buttonMinus);	
}

void MedSubmenu::removeButtons()
{
	compositor->removeRenderable(buttonPlus);
	compositor->removeRenderable(buttonMinus);
	inputMaster->removeInteractable(buttonPlus);
	inputMaster->removeInteractable(buttonMinus);	
}

void MedSubmenu::deinit()
{
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
	for(int i = 0 ; i < medSubmenuList->getCount() ; i++)
	{
		medSubmenuList->get(i)->unselect();
	}
	isSelected = true;
	addButtons();
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

void MedSubmenu::updatePos(Pos newPos)
{
	pos = newPos;
	if(buttonPlus != NULL && buttonMinus != NULL)
	{
		buttonPlus->updatePos(pos+Pos((size.x-6)/2+4  ,2));
		buttonMinus->updatePos(pos+Pos((size.x-6)/2+4  ,(size.y-6)/2+4));
	}
	else
	{
		printf("WARNING POS UPDATED IN MED SUBMENU BEFORE INIT !\n");
	}
}