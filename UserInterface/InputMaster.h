#ifndef _INPUT_MASTER_H_
#define _INPUT_MASTER_H_

#include "TouchController.h"

#include "Interactable.h"

#include "UIHelper.h"

#include <cstring>


class InputMaster
{
public:
	InputMaster(TouchController * newTouchController);

	void addInteractable(Interactable * newInteractable);
	void removeInteractable(Interactable * oldInteractable);

	void work();




private:
	TouchController * touchController;

	List<Interactable> interactableList;

	bool checkBoundingBox(Interactable * interactable, Pos point);

	int searchInteractable(Pos pos, InteractMode interactMode);

	void interact(Pos pos, InteractMode interactMode);

	int computeDistance(Pos posA, Pos posB);

	int continuousCount;
	Pos continuousPos;
	bool isSwipe;
	bool isDone;
};

#endif // _INPUT_MASTER_H_
