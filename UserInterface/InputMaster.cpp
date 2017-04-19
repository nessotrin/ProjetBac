#include "InputMaster.h"
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <GL/glut.h>

#include <unistd.h>//sleep

InputMaster::InputMaster(TouchController * newTouchController)
{
	touchController = newTouchController;
	isDone = false;
	isSwipe = false;
	continuousCount = 0;
}

void InputMaster::addInteractable(Interactable * newInteractable)
{
	interactableList.add(newInteractable);
}


void InputMaster::removeInteractable(Interactable * oldInteractable)
{
	interactableList.remove(oldInteractable);
}


#define CLICK_TIME_THRESHOLD 10
#define SWIPE_THRESHOLD_DIST 10

#include <SDL2/SDL.h>
void InputMaster::work()
{
	SDL_PumpEvents();
	int x,y;
	if (SDL_GetMouseState(&x, &y) & SDL_BUTTON(SDL_BUTTON_LEFT))
	{
		if(!isDone)
		{
			if(continuousCount == 0)
			{
				isSwipe = false;
				continuousPos = Pos(x,y);
			}
			if(computeDistance(Pos(x,y),continuousPos) > SWIPE_THRESHOLD_DIST)
			{
				isSwipe = true;
			}
			if(continuousCount > CLICK_TIME_THRESHOLD)
			{
				if(isSwipe == false)
				{
					isDone = true;
					printf("Click\n");
					interact(continuousPos, InteractClick);
				}
			}
			if(isSwipe == true)
			{
				printf("Swipe ! %d %d\n",x,y);
				interact(Pos(x,y),InteractSwipe);
			}
		}
		
		continuousCount++;
		
		printf("Pressed !\n");
	}
	else
	{
		isDone = false;

		if(!isDone && continuousCount > 0 && isSwipe == false)
		{
			printf("fast Click!\n");
			interact(continuousPos, InteractClick);
		}

		continuousCount = 0;

	}	
	
	//printf("x %d y %d\n",x,y);
	
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


int InputMaster::searchInteractable(Pos pos, InteractMode interactMode)
{
	printf("Input handled ! mode %d at %d %d (%d interactables)\n",interactMode,pos.x,pos.y,interactableList.getCount());
	
	int HighestZId = -1;
	int HighestZHeight = -1;
	
	for(int i = 0 ; i < interactableList.getCount() ; i++)
	{
		if(checkBoundingBox(interactableList.get(i),pos) && (interactableList.get(i)->allowedInteractMode & interactMode) )
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
		return -1;
	}
	else
	{
		printf("Clicked on interactable %d\n",HighestZId);
		return HighestZId;
	}
}


void InputMaster::interact(Pos pos, InteractMode interactMode)
{
	int id = searchInteractable(pos, InteractSwipe);
	if(id >= 0)
	{
		interactableList.get(id)->interact(Pos(pos.x - interactableList.get(id)->pos.x,
											   pos.y - interactableList.get(id)->pos.y),
										   interactMode);
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

int InputMaster::computeDistance(Pos posA, Pos posB)
{
	return sqrt(pow(posA.x-posB.x,2)+pow(posA.y-posB.y,2));
}