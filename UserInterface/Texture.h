#ifndef _TEXTURE_H_
#define _TEXTURE_H_

#include "UIHelper.h"

#ifndef BBB
#include <GL/gl.h>
#else
#include <GLES2/gl2.h>
#endif


class Texture
{
public:
	Texture(unsigned char * bitmap, Size newSize, bool smoothTexture);
	Texture(GLuint newGLtexture, Size newSize);
	Texture();

	void Delete();

	GLuint GLtexture;

	Size size;


private:

};

#endif // _TEXTURE_H_
