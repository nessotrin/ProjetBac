#ifndef _FONT_RENDERER_H_
#define _FONT_RENDERER_H_

#include "UIHelper.h"

class FontRenderer
{
public:

	static bool loadFonts();
	static void printText(char * text, unsigned char color[4], Pos pos, Size size);
	static void printTextCentered(char * text, unsigned char color[4], Pos pos, Size size);
	static Size calculateTextSize(char * text, Size size);


private:

	static Size getLetterTextureSize(int sizeX);
	static int getCharacterOffset(char character, int sizeX);
	static int getCharacterSpacing(int sizeX);
	static int getDefaultSizeY(int sizeX);
	

	
};

#endif // _FONT_RENDERER_H_
