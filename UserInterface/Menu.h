#ifndef _MENU_H_
#define _MENU_H_

#include "Compositor.h"
#include "InputMaster.h"

class Menu
{
public:
	Menu(Compositor * newCompositor, InputMaster * newInputMaster, List<Menu> * newMenuList);
	virtual bool isDone() = 0;
	virtual void work() = 0;
	virtual void init() = 0;
	virtual void deinit() = 0;

protected:

	Compositor * compositor;
	InputMaster * inputMaster;
	List<Menu> * menuList;

private:

};

#endif // _MENU_H_
