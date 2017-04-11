#include "Menu.h"

Menu::Menu(Compositor * newCompositor, InputMaster * newInputMaster, List<Menu> * newMenuList)
{
	compositor = newCompositor;
	inputMaster = newInputMaster;
	menuList = newMenuList;
}