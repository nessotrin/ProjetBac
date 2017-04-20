#ifndef _SCROLLABLE_TABLE_H_
#define _SCROLLABLE_TABLE_H_

#include "Menu.h"
#include "Interactable.h"


class ScrollableTable : public Menu, Interactable
{
public:

	ScrollableTable(Compositor * newCompositor, InputMaster * newInputMaster, List<Menu> * newMenuList,
					int newElementPerLine, int newElementPerColumn,Size newElementSize, Size newElementMargin, unsigned char newBackgroundColor[4], int newZHeight, Pos newPos, Size newSize);
	bool isDone();
	void render(Pos pos);
	
	void add(Renderable * newRenderable);
	void remove(Renderable * oldRenderable);
	
	void init();
	void deinit();
	
	void work();
	
	void interact(Pos pos, InteractMode interactMode, bool isRepeated);
	

private:

	unsigned char backgroundColor[4];

	List<Renderable> elementList;

	int elementPerLine;
	int elementPerColumn;
	Size elementSize;
	Size elementMargin;

	int scrollPos;
	Pos lastInteractPos;
};

#endif // _SCROLLABLE_TABLE_H_
