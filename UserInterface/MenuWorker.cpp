#include "MenuWorker.h"



#include "Compositor.h"
#include "TouchController.h"
#include "InputMaster.h"

#include "MainMenu.h"

#include <unistd.h>//sleep

#include <cstdio>

MenuWorker::MenuWorker(OpenGLHolder * newOpenGLHolder)
{
	openGLHolder = newOpenGLHolder;
}

 #include "GLHelper.h"

OpenGLHolder * GLOBALopenGLHolder;


void MenuWorker::work()
{
	TouchController touchController;
	InputMaster inputMaster(&touchController);
	Compositor compositor;
	
	MainMenu mainMenu(&compositor, &inputMaster, &menuList);
	mainMenu.init();
	
	printf("Starting loop ! \n");
	
	GLOBALopenGLHolder = openGLHolder;

	
	while(1)
	{
//		printf("Looping ...\n");
		openGLHolder->beginFrame();

		compositor.render();

		mainMenu.work();

		inputMaster.work();


		
		openGLHolder->finishFrame();
		
		/*
		for(int i = 0 ; i < menuList.getCount() ; i++)
		{
			if(menuList.get(i)->isDone())
			{
				delete menuList.get(i);
				menuList.remove(menuList.get(i));
				i--;
			}
		}
		*/
		usleep(10000);
	}

	printf("Finished loop ! \n");
}
