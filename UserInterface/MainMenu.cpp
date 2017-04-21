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
	mainButton->work();
	
	for(int i = 0 ; i < medSubmenuList->getCount() ; i++)
	{
		medSubmenuList->get(i)->work();
	}
	
}



	
	Texture testImg;
	Texture test2Img;


	


void MainMenu::init()
{
	//unsigned char data[] = {50,50,255,255};

	
	testImg = BMPLoader::load("test.bmp");

	
	test2Img = BMPLoader::load("test2.bmp");


//	printf("---%d %d\n",testImg.GLtexture,test2Img.GLtexture);



	mainButton = new Button(Pos(10,10), Size(50,50), 255, this, 0, testImg, testImg);


	compositor->addRenderable(mainButton);
	inputMaster->addInteractable(mainButton);
	
	//printf("Main menu init'ed\n");
	
	unsigned char color[] = {255,255,220,255};
	
	
	medSubmenuList = new List<MedSubmenu>;

	
	scrollableTable = new ScrollableTable(compositor,inputMaster,menuList,1,Pos(0,0),Size(540,480),4,-1,Size(100,100),Size(10,10),Size(-1,50),color);



	for(int i = 0 ; i < 100 ; i++)
	{

		MedSubmenu * sub = new MedSubmenu(Pos(0,0), Size(100,100), 2, compositor,inputMaster,menuList,medSubmenuList);
		sub->init();
		medSubmenuList->add(sub);		
		scrollableTable->add(sub);
		inputMaster->addInteractable(sub);

	}

	scrollableTable->init();
	
}

void MainMenu::deinit()
{
	
}