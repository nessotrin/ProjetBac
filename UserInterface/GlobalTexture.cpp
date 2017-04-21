#include "GlobalTexture.h"

Texture GlobalTexture::plusTexture;
Texture GlobalTexture::plusTextureActive;
Texture GlobalTexture::minusTexture;
Texture GlobalTexture::minusTextureActive;

#include "BMPLoader.h"


bool GlobalTexture::load()
{
	plusTexture = BMPLoader::load("plusTexture.bmp", true);
	plusTextureActive = BMPLoader::load("plusTextureActive.bmp", true);
	minusTexture = BMPLoader::load("minusTexture.bmp", true);
	minusTextureActive = BMPLoader::load("minusTextureActive.bmp", true);
	return false;
}


