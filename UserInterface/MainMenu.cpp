#include "MainMenu.h"

#include "BMPLoader.h"

#include <cstdio>

#include <cstdlib>

MainMenu::MainMenu(Compositor * newCompositor, InputMaster * newInputMaster, List<Menu> * newMenuList) : Menu::Menu(newCompositor, newInputMaster, newMenuList)
{
	
}

void MainMenu::callback(int id)
{
	if(id == 0)
	{
		printf("Main button pressed ! \n");
		mainButton->pos.x += rand()%100;
		mainButton->pos.y -= rand()%100;

		if(mainButton->pos.x >= 640-mainButton->size.x)
		{
			mainButton->pos.x -= 640-mainButton->size.x;
		}

		if(mainButton->pos.x < 0)
		{
			mainButton->pos.x += 640-mainButton->size.x;			
		}

		if(mainButton->pos.y >= 480-mainButton->size.y)
		{
			mainButton->pos.y -= 480-mainButton->size.y;
		}

		if(mainButton->pos.y < 0)
		{
			mainButton->pos.y += 480-mainButton->size.y;			
		}



	}
}

bool MainMenu::isDone()
{
	return false;
}


void MainMenu::work()
{
	
}

void MainMenu::init()
{
	unsigned char rawTexture[36] =
{255,255,255,255,     20, 20, 20,255,      20, 20, 20,255,
 255,255,255,255,      0,  0,255,255,      20, 20, 20,255,
 255,255,255,255,      0,  0,255,255,      20, 20, 20,255,	
};

	TextureData testImg = BMPLoader::load("test.bmp");

	mainButtonTexture = new Texture(testImg.buffer, testImg.size);


	mainButton = new Button(this,0,Pos(10,10),Size(50,50),mainButtonTexture,0);

	compositor->addRenderable(mainButton);
	inputMaster->addInteractable(mainButton);
	
	printf("Main menu init'ed\n");

}

void MainMenu::deinit()
{
	
}