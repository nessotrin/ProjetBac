#include "TextureHelper.h"

#include "GLHelper.h"

#include <cstdio>

GLint TextureHelper::loadTexture(unsigned char * buffer, Size size)
{
	GLuint newTexture;

//	glPixelStorei(GL_UNPACK_ALIGNMENT, 1); ??
//	glPixelStorei(GL_PACK_ALIGNMENT, 1);
	glGenTextures(1, &newTexture);

	GLHelper::CheckForErrors("glGenTextures");


	glBindTexture(GL_TEXTURE_2D, newTexture); // tell openGL that we are using the texture 

	GLHelper::CheckForErrors("glBindTexture");

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_BASE_LEVEL, 0);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, 0);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);	 
	printf("Bind %d %d\n",size.x, size.y);

/*
	for(int i = 0 ; i < size.x*size.y*4 ; i+=4)
	{
		printf("%d %d %d %d \n",buffer[i],buffer[i+1],buffer[i+2],buffer[i+3]);
	}
*/
	
	 
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, (GLsizei) size.x, (GLsizei) size.y, 0, GL_RGBA, GL_UNSIGNED_BYTE, (GLvoid*)buffer);

	GLHelper::CheckForErrors("glTexImage2D");

	return newTexture;
}
