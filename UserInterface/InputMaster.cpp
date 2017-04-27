#include "InputMaster.h"
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <GL/glut.h>

#include <unistd.h>//sleep

InputMaster::InputMaster(TouchController * newTouchController)
{
	touchController = newTouchController;
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


#define CLICK_TIME_THRESHOLD 3
#define SWIPE_THRESHOLD_DIST 2 //10 -> high DPI screen

#include <SDL2/SDL.h>
void InputMaster::work()
{
	SDL_PumpEvents();
	int x,y;
	bool isTouched = false;
	if (SDL_GetMouseState(&x, &y) & SDL_BUTTON(SDL_BUTTON_LEFT))
	{
		handleInput(Pos(x,y), true);
		isTouched = true;
	}
	else
	{
		if(continuousCount > 0 && !isLocked) // clicked so fast it wasn't registered
		{
//			printf("fast Click!\n");
			interact(startPos, searchInteractable(startPos,InteractClick), InteractClick, false);
		}

		continuousCount = 0;
		isLocked = false;
		isDone = false;
	}	
	
	//printf("x %d y %d\n",x,y);
	
	
	
	Pos pos = touchController->getCursorPos();
	
	if(pos.x > 0   &&
	   pos.x < 640 &&
	   pos.y < 0   &&
	   pos.y < 480)
	{
		handleInput(pos,true);
		isTouched = true;
	}
	
	if(!isTouched)
	{
		handleInput(Pos(-1,-1),false);
	}
	
}
/* DEBUG
#include "GLHelper.h"

#include "OpenGLHolder.h"

extern OpenGLHolder * GLOBALopenGLHolder;

#include <unistd.h>
*/

void InputMaster::handleInput(Pos pos, bool isTouched)
{
	if(isTouched)
	{
		if(!isDone)
		{
			if(isLocked)
			{
				if(isSwipe == true)
				{
					interact(pos,startId,InteractSwipe, isRepeated);
				}
				else
				{
					if(startId == searchInteractable(startPos,InteractClick))
					{
						interact(startPos, startId, InteractClick, isRepeated);				
					}
					else
					{
						isDone = true;
					}
				}
				isRepeated = true;
			
			}
			else
			{
				if(continuousCount == 0)
				{
					isRepeated = false;
					isSwipe = false;
					startPos = pos;
				}
				if(computeDistance(pos,startPos) > SWIPE_THRESHOLD_DIST)
				{
					isSwipe = true;
					isLocked = true;
					startId = searchInteractable(startPos,InteractSwipe);
				}
				if(continuousCount >= CLICK_TIME_THRESHOLD)
				{	
					isSwipe = false;
					isLocked = true;
					startId = searchInteractable(startPos,InteractClick);
				}
			}
		
			continuousCount++;
		
//			printf("Pressed !\n");
		}
	}
	else
	{
		if(continuousCount > 0 && !isLocked) // clicked so fast it wasn't registered
		{
//			printf("fast Click!\n");
			interact(startPos, searchInteractable(startPos,InteractClick), InteractClick, false);
		}

		continuousCount = 0;
		isLocked = false;
		isDone = false;
	}	
}

int InputMaster::searchInteractable(Pos pos, InteractMode interactMode)
{
	//printf("Input handled ! mode %d at %d %d (%d interactables)\n",interactMode,pos.x,pos.y,interactableList.getCount());
	
	int HighestZId = -1;
	int HighestZHeight = -1;
	
	for(int i = 0 ; i < interactableList.getCount() ; i++)
	{
		/* INPUT DEBUGGER */ /*(
		GLOBALopenGLHolder->beginFrame();
		unsigned char color[] = {rand()%255,rand()%255,rand()%255,255};
		GLHelper::drawColorSquare(interactableList.get(i)->pos,interactableList.get(i)->size,color,0,0,0);
		GLOBALopenGLHolder->finishFrame();
		usleep(200000);
		*/
 
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
//		printf("Clicked on NOTHING !\n");
		return -1;
	}
	else
	{
//		printf("Search on interactable %d (%dx%d)\n",HighestZId,pos.x,pos.y);
		return HighestZId;
	}
}


void InputMaster::interact(Pos currentPos, int id, InteractMode interactMode, bool isRepeated)
{
	if(id >= 0)
	{
		interactableList.get(id)->interact(Pos(currentPos.x - interactableList.get(id)->pos.x,
											   currentPos.y - interactableList.get(id)->pos.y),
										   interactMode, isRepeated);
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
