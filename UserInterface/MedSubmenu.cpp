#include "MedSubmenu.h"

#include "GlobalTexture.h"

#include "GLHelper.h"

#include "FontRenderer.h"

#include <cstring>


MedSubmenu::MedSubmenu(Pos newPos, Size newSize, int newZHeight, Compositor * newCompositor, InputMaster * newInputMaster, List<Menu> * newMenuList, List<MedSubmenu> * newMedSubmenuList) : Menu(newPos, newSize, newZHeight, InteractClick, newCompositor, newInputMaster, newMenuList)
{
	medSubmenuList = newMedSubmenuList;
	
	isSelected = false;
	
	buttonPlus = NULL;
	buttonMinus = NULL;
	
	count = 0;
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
	buttonPlus = new Button(Pos(-1,-1), Size((size.x-6)/3,(size.y-6)/2), ZHeight+1, this, 0, GlobalTexture::plusTexture, GlobalTexture::plusTextureActive, 30,10);
	buttonMinus = new Button(Pos(-1,-1), Size((size.x-6)/3,(size.y-6)/2), ZHeight+1, this, 1, GlobalTexture::minusTexture, GlobalTexture::minusTextureActive, 30,10);
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

	unsigned char colorText[4];
	if(count == 0)
	{
		colorText[0] = 40;
		colorText[1] = 40;
		colorText[2] = 255;
		colorText[3] = 110;
	}
	else
	{
		int redAdd = 20*count;
		if(redAdd > 255-50)
		{
			redAdd = 255-50;
		}
		colorText[0] = 50+redAdd;
		colorText[1] = 20;
		colorText[2] = 20;
		colorText[3] = 200;		
	}
	
	if(isSelected || count > 0)
	{
		char text[64]; //>63 decimal number = not any time soon
		
		sprintf(text,"%d",count);

		Pos offset(0,23);
		
		if(isSelected)
		{
			offset.x = size.x*(2/(float)5) -40;
		}
		else
		{
			offset.x = size.x*(1/(float)2) -40;			
		}
		
		if(count < 10)
		{
			offset.x += 25;
		}

		FontRenderer::printText(text,colorText,pos+offset,50,-1);

	}

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
		count++;
	}
	else
	{
		printf("REMOVE");		
		count--;
		if(count < 0)
		{
			count = 0;
		}
	}
}

void MedSubmenu::updatePos(Pos newPos)
{
	pos = newPos;
	if(buttonPlus != NULL && buttonMinus != NULL)
	{
		buttonPlus->updatePos(pos+Pos((size.x-6)*0.66+4  ,2));
		buttonMinus->updatePos(pos+Pos((size.x-6)*0.66+4  ,(size.y-6)/2+4));
	}
	else
	{
		printf("WARNING POS UPDATED IN MED SUBMENU BEFORE INIT !\n");
	}
}