#ifndef _SCROLLABLE_TABLE_H_
#define _SCROLLABLE_TABLE_H_

#include "Menu.h"
#include "Interactable.h"


class ScrollableTable : public Menu, Interactable
{
public:

	ScrollableTable(Compositor * newCompositor, InputMaster * newInputMaster, List<Menu> * newMenuList, int newZHeight, Pos newPos, Size newSize, 
					int newElementPerLine, int newElementPerColumn,Size newElementSize, Size newElementMargin, Size newBorderMargin, unsigned char newBackgroundColor[4]);
	bool isDone();
	void render(Pos pos);
	
	void add(Interactable * newRenderable);
	void remove(Interactable * oldRenderable);
	
	void init();
	void deinit();
	
	void work();
	
	void interact(Pos pos, InteractMode interactMode, bool isRepeated);
	
	Interactable * getElement(int id);
	int getElementCount();
	
private:

	void updateBorderMargin();

	void updateElementsPos();

	Pos calculateElementPos(int id);

	unsigned char backgroundColor[4];

	List<Interactable> elementList;

	int elementPerLine;
	int elementPerColumn;
	Size elementSize;
	Size elementMargin;

	Size borderMargin;

	int scrollPos;
	Pos lastInteractPos;
	
};

#endif // _SCROLLABLE_TABLE_H_
