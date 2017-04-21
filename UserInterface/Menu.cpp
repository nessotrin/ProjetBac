#include "Menu.h"

Menu::Menu(Pos newPos, Size newSize, int newZHeight, unsigned char newAlpha, InteractMode newAllowedInteractMode, Compositor * newCompositor, InputMaster * newInputMaster, List<Menu> * newMenuList) : Interactable(newPos, newSize, newZHeight, newAlpha, newAllowedInteractMode)
{
	compositor = newCompositor;
	inputMaster = newInputMaster;
	menuList = newMenuList;
}