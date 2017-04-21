#include "TextureHelper.h"

#include "GLHelper.h"

#include <cstdio>

GLuint TextureHelper::loadTexture(unsigned char * buffer, Size size, bool smoothTexture)
{
	GLuint newTexture = 500;
/*
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glPixelStorei(GL_PACK_ALIGNMENT, 1);
*/
	glGenTextures(1, &newTexture);

	//printf("Gen'ed %d\n",newTexture);

	GLHelper::CheckForErrors("glGenTextures");


	glBindTexture(GL_TEXTURE_2D, newTexture); // tell openGL that we are using the texture 

	GLHelper::CheckForErrors("glBindTexture");

	//printf("Bind %d %d [%d]\n",size.x, size.y,buffer);

/*
	for(int i = 0 ; i < size.x*size.y*4 ; i+=4)
	{
		printf("%d %d %d %d \n",buffer[i],buffer[i+1],buffer[i+2],buffer[i+3]);
	}
*/
	if(smoothTexture)
	{
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR); 
		glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP, GL_TRUE); 
	}
	else
	{
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); 		
	}


	 
	 
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, (GLsizei) size.x, (GLsizei) size.y, 0, GL_RGBA, GL_UNSIGNED_BYTE, (GLvoid*)buffer);
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, (GLsizei) 2, (GLsizei) 2, 0, GL_RGBA, GL_UNSIGNED_BYTE, (GLvoid*)buf);

	GLHelper::CheckForErrors("glTexImage2D");

/*
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_BASE_LEVEL, 0);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, 0);
*/



	return newTexture;
}