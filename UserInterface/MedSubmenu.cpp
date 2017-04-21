#include "MedSubmenu.h"

#include "GlobalTexture.h"

#include "GLHelper.h"

#include "FontRenderer.h"

#include <cstring>


MedSubmenu::MedSubmenu(Pos newPos, Size newSize, int newZHeight, unsigned char newAlpha, Compositor * newCompositor, InputMaster * newInputMaster, List<Menu> * newMenuList, List<MedSubmenu> * newMedSubmenuList, Texture newBackgroundTexture) : Menu(newPos, newSize, newZHeight, newAlpha, InteractClick, newCompositor, newInputMaster, newMenuList)
{
	medSubmenuList = newMedSubmenuList;
	
	isSelected = false;
	
	buttonPlus = NULL;
	buttonMinus = NULL;
	
	count = 0;

	backgroundTexture = newBackgroundTexture;
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
	buttonPlus = new Button(Pos(-1,-1), Size((size.x-6)/3,(size.y-6)/2), ZHeight+1, 255, this, 0, GlobalTexture::plusTexture, GlobalTexture::plusTextureActive, 30,10);
	buttonMinus = new Button(Pos(-1,-1), Size((size.x-6)/3,(size.y-6)/2), ZHeight+1, 255, this, 1, GlobalTexture::minusTexture, GlobalTexture::minusTextureActive, 30,10);
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
		color[0] = 255;		
		color[1] = 255;
		color[2] = 255;
	}
	else
	{
		color[0] = 255;		
		color[1] = 255;
		color[2] = 100;
	}
	color[3] = 255;
	
	GLHelper::alphaOnRGBA(color,alpha);
	
	GLHelper::drawColoredTexturedSquare(pos,size,color,backgroundTexture.GLtexture,0,0,0);

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
		int redAdd = 10*count;
		if(redAdd > 50)
		{
			redAdd = 50;
		}
		colorText[0] = 50+redAdd;
		colorText[1] = 20;
		colorText[2] = 20;
		colorText[3] = 255;		
	}
	
	GLHelper::alphaOnRGBA(colorText,alpha);

	
	if(isSelected || count > 0)
	{
		char text[64]; //>63 decimal number = not any time soon
		
		sprintf(text,"%d",count);

		Pos offset(0,50);
		
		if(isSelected)
		{
			offset.x = size.x*(2/(float)5);
		}
		else
		{
			offset.x = size.x*(1/(float)2);			
		}
		

		FontRenderer::printTextCentered(text,colorText,pos+offset,Size(50,-1));

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
	
	if(count > 0)
	{
		buttonPlus->setAlpha(150);
		buttonMinus->setAlpha(150);
	}
	else
	{
		buttonPlus->setAlpha(255);
		buttonMinus->setAlpha(255);		
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