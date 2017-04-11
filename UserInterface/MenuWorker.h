#ifndef _MENU_WORKER_H_
#define _MENU_WORKER_H_

#include "OpenGLHolder.h"

#include "UIHelper.h"

#include "Menu.h"

class MenuWorker
{
public:
	MenuWorker(OpenGLHolder * newOpenGLHolder);
	
	void work();


private:

	OpenGLHolder * openGLHolder;

	List<Menu> menuList;
};

#endif // _MENU_WORKER_H_
