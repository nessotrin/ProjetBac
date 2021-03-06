#ifndef _MAIN_MENU_H_
#define _MAIN_MENU_H_

#include "Menu.h"
#include "Callbackable.h"

#include "Button.h"
#include "Texture.h"
#include "ScrollableTable.h"

#include "MedSubmenu.h"


class MainMenu : public Menu, Callbackable
{
public:

	MainMenu(Pos newPos, Size newSize, int newZHeight, unsigned char newAlpha, Compositor * newCompositor, InputMaster * newInputMaster, List<Menu> * newMenuList);
	
	void callback(int id);

	bool isDone();
	void work();
	
	void init();
	void deinit();

	void render(Pos offset);
	void interact(Pos interactPos, InteractMode currentInteractMode, bool isRepeated);


private:

	Button * mainButton;
	Texture * mainButtonTexture;
	ScrollableTable * scrollableTable;
	List<MedSubmenu> * medSubmenuList;


};

#endif // _MAIN_MENU_H_
