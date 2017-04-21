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

	void interact(Pos currentPos, int id, InteractMode interactMode, bool isRepeated);

	int computeDistance(Pos posA, Pos posB);

	int continuousCount;
	Pos startPos;
	bool isSwipe;
	bool isLocked;
	bool isRepeated;
	bool isDone;
	int startId;
};

#endif // _INPUT_MASTER_H_
