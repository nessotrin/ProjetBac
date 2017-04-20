#include "GlobalTexture.h"

Texture GlobalTexture::plusTexture;
Texture GlobalTexture::minusTexture;

#include "BMPLoader.h"


bool GlobalTexture::load()
{
	plusTexture = BMPLoader::load("test.bmp");
	minusTexture = BMPLoader::load("test.bmp");
	return false;
}


