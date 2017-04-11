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

	void handleInput(Pos pos);

};

#endif // _INPUT_MASTER_H_
