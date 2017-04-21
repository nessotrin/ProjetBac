#include "Menu.h"

Menu::Menu(Pos newPos, Size newSize, int newZHeight, InteractMode newAllowedInteractMode, Compositor * newCompositor, InputMaster * newInputMaster, List<Menu> * newMenuList) : Interactable(newPos, newSize, newZHeight, newAllowedInteractMode)
{
	compositor = newCompositor;
	inputMaster = newInputMaster;
	menuList = newMenuList;
}