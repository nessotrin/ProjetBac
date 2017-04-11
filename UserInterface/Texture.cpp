#include "Texture.h"

#include "TextureHelper.h"



Texture::Texture(unsigned char * bitmap, Size newSize)
{
	GLtexture = TextureHelper::loadTexture(bitmap, newSize);
	size = newSize;
}

Texture::~Texture()
{
	glDeleteTextures(1, &GLtexture);
}

