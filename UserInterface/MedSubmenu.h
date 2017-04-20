#ifndef _MED_SUBMENU_H_
#define _MED_SUBMENU_H_

#include <Menu.h>
#include <Renderable.h>
#include <Interactable.h>
#include <ScrollableTable.h>
#include <Callbackable.h>

#include <Button.h>

class MedSubmenu : Menu, Interactable, Callbackable
{
public:

	MedSubmenu(Compositor * newCompositor, InputMaster * newInputMaster, List<Menu> * newMenuList, ScrollableTable * newScrollableTable, Pos newPos);


	void unselect();

	bool isDone();
	void work();
	void init();
	void deinit();

	void render(Pos pos);

	void interact(Pos pos, InteractMode currentInteractMode, bool isRepeated);

	void callback(int id);

private:

	bool isSelected;
	
	ScrollableTable * scrollableTable;
	
	Button * buttonPlus;
	Button * buttonMinus;
};

#endif // _MED_SUBMENU_H_
