#ifndef _MED_SUBMENU_H_
#define _MED_SUBMENU_H_

#include <Menu.h>
#include <Renderable.h>
#include <Interactable.h>
#include <ScrollableTable.h>
#include <Callbackable.h>

#include <Button.h>
#include "MedSubmenu.h"


class MedSubmenu : public Menu, public Callbackable
{
public:

	MedSubmenu(Pos newPos, Size newSize, int newZHeight, unsigned char newAlpha, Compositor * newCompositor, InputMaster * newInputMaster, List<Menu> * newMenuList, List<MedSubmenu> * newMedSubmenuList, Texture newBackgroundTexture);


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
	
	Texture backgroundTexture;
	
	int count;
};

#endif // _MED_SUBMENU_H_
