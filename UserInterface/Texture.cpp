#include "Texture.h"

#include "TextureHelper.h"


Texture::Texture()
{
	
}

Texture::Texture(unsigned char * bitmap, Size newSize)
{
	printf("Loading TEXTURE\n");
	GLtexture = TextureHelper::loadTexture(bitmap, newSize);
	printf("Got %d\n",GLtexture);
	size = newSize;
}

Texture::Texture(GLuint newGLtexture, Size newSize)
{
	GLtexture = newGLtexture;
	size = newSize;
}

void Texture::Delete()
{
	glDeleteTextures(1, &GLtexture);
}

