#ifndef _BMP_LOADER_H_
#define _BMP_LOADER_H_

#include "UIHelper.h"

class TextureData
{
public:

	TextureData()
	{
		buffer = NULL;
		size.x = -1;
		size.y = -1;
	}

	unsigned char * buffer;
	Size size;
};

class BMPLoader
{
public:
	static TextureData load(char * name);


private:

	static bool readBMP(unsigned char * rawData, int rawDataSize, TextureData * textureData);
	static bool getRawData(unsigned char ** rawData, int * size, char * name);
	static int getRawSize(FILE * imgFile);
	static void error(char * name, char * where);

	static void copyColorBytesBGR(unsigned char * rgbaBuffer, unsigned char * rgbBuffer, int count);
	static void copyColorBytesABGR(unsigned char * rgbaBuffer, unsigned char * rgbBuffer, int count);

	static int addPaddingFor4Bytes(int size);
	static int ucharToInt(unsigned char * buffer, int offset);
	static unsigned short ucharToUShort(unsigned char * buffer, int offset);


};

#endif // _BMP_LOADER_H_
