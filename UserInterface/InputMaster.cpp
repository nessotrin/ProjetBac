#include "InputMaster.h"
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <GL/glut.h>

#include <unistd.h>//sleep

InputMaster::InputMaster(TouchController * newTouchController)
{
	touchController = newTouchController;
}

void InputMaster::addInteractable(Interactable * newInteractable)
{
	interactableList.add(newInteractable);
}


void InputMaster::removeInteractable(Interactable * oldInteractable)
{
	interactableList.remove(oldInteractable);
}


#include <SDL2/SDL.h>
void InputMaster::work()
{
	SDL_PumpEvents();
	int x,y;
	if (SDL_GetMouseState(&x, &y) & SDL_BUTTON(SDL_BUTTON_LEFT))
	{
		handleInput(Pos(x,y));
	}
	
	
	/*
	
	Pos pos = touchController->getCursorPos();
	
	if(pos.x > 0   &&
	   pos.x < 640 &&
	   pos.y < 0   &&
	   pos.y < 480)
	{
		handleInput(pos);
	}
	
	*/
}


void InputMaster::handleInput(Pos pos)
{
	printf("Input handled ! %d %d (%d interactables)\n",pos.x,pos.y,interactableList.getCount());
	
	int HighestZId = -1;
	int HighestZHeight = -1;
	
	for(int i = 0 ; i < interactableList.getCount() ; i++)
	{
		if(checkBoundingBox(interactableList.get(i),pos))
		{
			if(HighestZHeight == interactableList.get(i)->ZHeight)
			{
				printf("WARNING /!\\ WARNING\nOVERLAPING INTERACTABLES ///!\\\\\\ \n");
			}
			else if(HighestZHeight < interactableList.get(i)->ZHeight || HighestZHeight == -1)
			{
				HighestZHeight = interactableList.get(i)->ZHeight;
				HighestZId = i;
			}
		}
	}
	
	if(HighestZId == -1)
	{
		printf("Clicked on NOTHING !\n");
	}
	else
	{
		printf("Clicked on interactable %d\n",HighestZId);

		interactableList.get(HighestZId)->interact(Pos(pos.x - interactableList.get(HighestZId)->pos.x,
												       pos.y - interactableList.get(HighestZId)->pos.y));
		//sleep(1);
	}
	

}



bool InputMaster::checkBoundingBox(Interactable * interactable, Pos point)
{
	if(point.x >= interactable->pos.x && point.x <= interactable->pos.x+interactable->size.x &&
	   point.y >= interactable->pos.y && point.y <= interactable->pos.y+interactable->size.y)
	{
		return true;
	}
	
	return false;
}