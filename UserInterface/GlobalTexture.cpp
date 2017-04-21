#include "GlobalTexture.h"

Texture GlobalTexture::plusTexture;
Texture GlobalTexture::plusTextureActive;
Texture GlobalTexture::minusTexture;
Texture GlobalTexture::minusTextureActive;

#include "BMPLoader.h"


bool GlobalTexture::load()
{
	plusTexture = BMPLoader::load("plusTexture.bmp");
	plusTextureActive = BMPLoader::load("plusTextureActive.bmp");
	minusTexture = BMPLoader::load("minusTexture.bmp");
	minusTextureActive = BMPLoader::load("minusTextureActive.bmp");
	return false;
}


