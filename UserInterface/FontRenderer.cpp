#include "FontRenderer.h"

#include "Texture.h"
#include "BMPLoader.h"
#include "GLHelper.h"


Texture * fontMap;
int * fontOffsetMap;


bool FontRenderer::loadFonts()
{
	fontMap = (Texture*) malloc(sizeof(Texture) * (256));
	if(fontMap == NULL)
	{
		printf("Failed to alloc' fontMap !\n ");
		return true;
	}
	
	fontOffsetMap = (int*) malloc(sizeof(int) * (256));
	if(fontOffsetMap == NULL)
	{
		printf("Failed to alloc' fontOffsetMap !\n ");
		return true;
	}


	char defaultFilename[] = "font/default.bmp";
	Texture defaultTexture = BMPLoader::load(defaultFilename, false);
	if(defaultTexture.GLtexture == -1)
	{
		printf("Failed to load the default texture (\"%s\")\n ",defaultFilename);
		return true;
	}
	
	char filename[] = "font/ .bmp";
	
	for(int i = 0 ; i < 256 ; i++)
	{
		if((i == 0x21)               || // '?'
		   (i >= 0x30 && i <= 0x39)  || // 0-9
		   (i == 0x3F)               || // '!'
		   (i >= 0x41 && i <= 0x5A)  || // A-Z
		   (i >= 0x61 && i <= 0x7A))    // a-z
		{
			filename[5] = i;
			fontMap[i] = BMPLoader::load(filename, false);
			//printf("Loaded \"%s\"\n",filename);
			if(fontMap[i].GLtexture == -1)
			{
				printf("Failed to load the texture \"%c\" (%d) (\"%s\")\n ",i,i,fontMap);
				return true;
		
			}
		}
		else
		{
			fontMap[i] = defaultTexture;
		}

	}
	
	char offsetFileName[] = "font/offset.conf";
	
	
	FILE * offsetFile = fopen(offsetFileName,"r");
	if(offsetFile == NULL)
	{
		printf("Failed to open the conf file \"%s\" !\n",offsetFileName);
		return true;
	}
	
	
	int bufferWritePos = 0;
	char buffer[512];
	for(int i = 0 ; i < 256 ; i++)
	{
		bufferWritePos = 0;
		while (1)
		{
			if(fread(buffer+bufferWritePos, 1, 1, offsetFile) == 0)
			{
				printf("Font config file unexpectebly too short !\n");
				return true;
			}

			if(buffer[bufferWritePos] == '\n')
			{
				break;
			}

			bufferWritePos++;			
			
			if(bufferWritePos == 511)
			{
				printf("Font config: line too long (line %d) (%d long)\n",i,bufferWritePos);
				return true;
			}
		}
		
		buffer[bufferWritePos] = 0; //add the end of string
		
		int value;
		if(sscanf(buffer,"%d",&value) != 1)
		{
			printf("Font config: can't find number at line %d  \"\" !\n",i,buffer);
		}
		fontOffsetMap[i] = value;
		printf("%d \"%s\" %c\n",value,buffer,i);
	}
	
	
	return false;
}



void FontRenderer::printText(char * text, unsigned char color[4], Pos pos, Size size)
{
	if(size.y <= 0)
	{
		size.y = getDefaultSizeY(size.x);
	}

	int readPos = 0;
	Pos writePos = pos;
	while(text[readPos] != 0)
	{
//		printf("%d\n",text[readPos]);
		GLHelper::drawColoredTexturedSquare(writePos,size,color,fontMap[(unsigned char)text[readPos]].GLtexture,0,0,0);
		writePos.x +=  getCharacterOffset(text[readPos],size.x) + getCharacterSpacing(size.x);
		
	//	printf("| %c %d ",text[readPos],fontOffsetMap[(unsigned char)text[readPos]]);
		
		readPos++;
	}
	
	//printf("\n");
}

void FontRenderer::printTextCentered(char * text, unsigned char color[4], Pos pos, Size size)
{
	if(size.y <= 0)
	{
		size.y = getDefaultSizeY(size.x);
	}
	
	Size textSize = calculateTextSize(text,size);
	Pos newPos = pos - Pos(textSize.x/2,textSize.y/2);
	printText(text, color, newPos, size);
}



Size FontRenderer::calculateTextSize(char * text, Size size)
{
	int readPos = 0;
	int textSizeX = 0;
	while(text[readPos] != 0)
	{
		textSizeX += getCharacterOffset(text[readPos],size.x);
		readPos++;
	}
	
	textSizeX += getCharacterSpacing(size.x)*(readPos-1);
	
	
	return Size(textSizeX,size.y);
}

int FontRenderer::getCharacterSpacing(int sizeX)
{
	return sizeX/5;
}

int FontRenderer::getCharacterOffset(char character, int sizeX)
{
	return sizeX*(fontOffsetMap[character]/(float)64);
}

int FontRenderer::getDefaultSizeY(int sizeX)
{
	return sizeX*(74/(float)64);
}
