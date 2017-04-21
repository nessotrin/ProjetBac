#ifndef _MED_SUBMENU_H_
#define _MED_SUBMENU_H_

#include <Menu.h>
#include <Renderable.h>
#include <Interactable.h>
#include <ScrollableTable.h>
#include <Callbackable.h>

#include <Button.h>
#include "MedSubmenu.h"


class MedSubmenu : public Menu, public Interactable, Callbackable
{
public:

	MedSubmenu(Pos newPos, Size newSize, int newZHeight, Compositor * newCompositor, InputMaster * newInputMaster, List<Menu> * newMenuList, List<MedSubmenu> * newMedSubmenuList);


	void unselect();

	bool isDone();
	void work();
	void init();
	void deinit();


	void render(Pos pos);

	void interact(Pos pos, InteractMode currentInteractMode, bool isRepeated);

	void callback(int id);

	void updatePos(Pos newPos);

private:

	void addButtons();
	void removeButtons();

	bool isSelected;
	
	List<MedSubmenu> * medSubmenuList;
	
	Button * buttonPlus;
	Button * buttonMinus;
	
	int count;
};

#endif // _MED_SUBMENU_H_
