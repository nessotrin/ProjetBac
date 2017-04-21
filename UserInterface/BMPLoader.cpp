#include "BMPLoader.h"

#include <cstdlib>

#include <cstdio>

#include <cerrno>

#include "TextureHelper.h"

void BMPLoader::error(char * name, char * where)
{
	printf("ERROR: OPENING IMAGE \"%s\" at %s with errno %d\n",name,where,errno);	
}
	
	
int BMPLoader::getRawSize(FILE * imgFile)
{
	int rawDataSize;

	if(fseek(imgFile, 0L, SEEK_END) != 0)
	{
		return -1;
	}

	if((rawDataSize = ftell(imgFile)) == 0)
	{
		return -1;
	}

	if(fseek(imgFile, 0L, SEEK_SET) != 0)
	{
		return -1;
	}
	
	return rawDataSize;
}
	
Texture BMPLoader::load(char * name, bool smoothTexture)
{
	
	unsigned char * rawData = NULL;
	int rawDataSize;
	if(BMPLoader::getRawData(&rawData,&rawDataSize,name))
	{
		error(name, "getRawData");
		return Texture(-1,Size(0,0));
	}
	
	unsigned char * buffer = (unsigned char *)-1;
	Size size;

	if(BMPLoader::readBMP(rawData,rawDataSize,&buffer,&size))
	{
		error(name, "readBMP");
		return Texture(-1,Size(0,0));
	}
	
	
		
	GLuint textureInt = TextureHelper::loadTexture(buffer, size, smoothTexture);
	if(textureInt < 0)
	{
		error(name, "upload");
		return Texture(-1,Size(0,0));
	}

	
	return Texture(textureInt,size);
}

bool BMPLoader::getRawData(unsigned char ** rawData, int * size, char * name)
{
	FILE * imgFile;
	
	if((imgFile = fopen(name,"rb")) == NULL)
	{
		error(name, "fopen");
		return true;
	}
	
	*size = getRawSize(imgFile);

	//printf("size %d\n",*size);

	if(*size <= 0)
	{
		error(name, "getRawSize");
		return true;
	}
	
	*rawData = (unsigned char *) malloc(*size);
	
	if(*rawData == NULL)
	{
		error(name, "malloc");
		return true;
	}
		
	if(fread(*rawData, 1, *size, imgFile) != *size)
	{
		error(name, "fread");
		return true;
	}
	

	fclose(imgFile);

	return false;
}


bool BMPLoader::readBMP(unsigned char * rawData, int rawDataSize, unsigned char ** buffer, Size * size)
{
	/*
	printf("Bitmap marked \"%c%c\"\n",rawData[0],rawData[1]);
	
	printf("Bitmap reports size %dBytes\n",ucharToInt(rawData,2));

	printf("Bitmap data starts at 0x%x\n",ucharToInt(rawData,10));

	printf("Bitmap header size is %dB\n",ucharToInt(rawData,14));

	printf("Bitmap image is %dx%d\n",ucharToInt(rawData,18),ucharToInt(rawData,22));
	
	printf("Bitmap is %db per pixel\n",ucharToUShort(rawData,28));
	
	printf("Bitmap raw data is %dB\n",ucharToInt(rawData,34));
	
	*/ 
	
	int bytesPerPixel = ucharToUShort(rawData,28)/8;
	
	int bitmapDataStart = ucharToInt(rawData,10);
	
	size->x = ucharToInt(rawData,18);
	size->y = ucharToInt(rawData,22);

	
	(*buffer) = (unsigned char *) malloc(4*size->x*size->y);

	//printf("Alloc %d\n",4*size->x*size->y);
	if((*buffer) == NULL)
	{
		return true;
	}

	int bytesX = size->x*bytesPerPixel;
	int bytesXPadded = BMPLoader::addPaddingFor4Bytes(bytesX);
	int bytesXRGBA = size->x*4;

	for(int y = 0 ; y < size->y ; y++)
	{
		if(bytesPerPixel == 3)
		{
			BMPLoader::copyColorBytesBGR((*buffer)+(bytesXRGBA*(size->y-y-1)),
				   rawData            +(bytesXPadded*y) + bitmapDataStart,
				   size->x);			
		}
		else
		{
			BMPLoader::copyColorBytesABGR((*buffer)+(bytesXRGBA*(size->y-y-1)),
				   rawData            +(bytesXPadded*y) + bitmapDataStart,
				   size->x);			

		}
			   
			   
		/*
		int posX = 0;
		for(int j = 0 ; j < textureData->size.x ; j++)
		{
		
			printf("%x %x %x --- ",rawData [ bitmapDataStart +(bytesXPadded*y) + posX],
								  rawData [ bitmapDataStart +(bytesXPadded*y) + posX + 1],
								  rawData [ bitmapDataStart +(bytesXPadded*y) + posX + 2]);
		
			posX += bytesPerPixel;
		}
		*/
		
		//printf("\n%d --  %d|%d\n",y,bytesX*y,(bytesXPadded*y));
	}
	
	/*
	for(int i = 0 ; i < textureData->size.x*3*4 ; i++)
	{
		printf(" %x ",textureData->buffer[i]);
	}
*/
	return false;
}

int BMPLoader::addPaddingFor4Bytes(int size)
{
	if(size%4 > 0)
	{
		size += 4-(size%4);
	}
	
	return size;
}

int BMPLoader::ucharToInt(unsigned char * buffer, int offset)
{
	return buffer[offset] + (buffer[offset+1]<<8) + (buffer[offset+2]<<16) + (buffer[offset+3]<<24);
}

unsigned short BMPLoader::ucharToUShort(unsigned char * buffer, int offset)
{
	return buffer[offset] + (buffer[offset+1]<<8);
}

void BMPLoader::copyColorBytesBGR(unsigned char * rgbaBuffer, unsigned char * rgbBuffer, int count)
{

	int writePos = 0;
	for(int i = 0 ; i < count ; i++)
	{

		rgbaBuffer[writePos+0] = rgbBuffer[i*3+2];
		rgbaBuffer[writePos+1] = rgbBuffer[i*3+1];
		rgbaBuffer[writePos+2] = rgbBuffer[i*3];
		rgbaBuffer[writePos+3] = 255;
		writePos+= 4;
		//printf("At %d\n",writePos);
	}

}

void BMPLoader::copyColorBytesABGR(unsigned char * rgbaBuffer, unsigned char * rgbBuffer, int count)
{

	int writePos = 0;
	for(int i = 0 ; i < count ; i++)
	{
		rgbaBuffer[writePos+0] = rgbBuffer[i*4+3];
		rgbaBuffer[writePos+1] = rgbBuffer[i*4+2];
		rgbaBuffer[writePos+2] = rgbBuffer[i*4+1];
		rgbaBuffer[writePos+3] = rgbBuffer[i*4];
		writePos+= 4;
		//printf("At %d\n",writePos);
	}
}
