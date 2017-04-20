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
	unsigned char data[] = {50,50,255,255};
	TextureData tex;
	tex.buffer = data;
	tex.size = Size(1,1);
	
	TextureData testImg = BMPLoader::load("test.bmp");
	TextureData test2Img = BMPLoader::load("test2.bmp");


	printf("%dx%d\n",testImg.size.x,testImg.size.y);

	mainButtonTexture = new Texture(testImg.buffer, testImg.size);

	Texture * mainButtonTexture2 = new Texture(test2Img.buffer, test2Img.size);


	mainButton = new Button(this,0,Pos(10,10),Size(50,50),mainButtonTexture,255);


	compositor->addRenderable(mainButton);
	inputMaster->addInteractable(mainButton);
	
	printf("Main menu init'ed\n");
	
	unsigned char color[] = {255,255,220,255};
	
	scrollableTable = new ScrollableTable(compositor,inputMaster,menuList,3,2,Size(100,100),Size(30,30),color,1,Pos(0,0),Size(1000,1000));



	for(int i = 0 ; i < 100 ; i++)
	{
		Button * button1 = new Button(this,1,Pos(0,0),Size(100,100),mainButtonTexture2,2);
		scrollableTable->add(button1);
	}

	scrollableTable->init();
}

void MainMenu::deinit()
{
	
}