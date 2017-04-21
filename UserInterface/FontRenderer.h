#ifndef _FONT_RENDERER_H_
#define _FONT_RENDERER_H_

#include "UIHelper.h"

class FontRenderer
{
public:

	static bool loadFonts();
	static void printText(unsigned char * text, unsigned char color[4], Pos pos, int sizeX, int sizeY);


};

#endif // _FONT_RENDERER_H_
