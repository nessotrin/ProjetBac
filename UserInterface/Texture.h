#ifndef _TEXTURE_H_
#define _TEXTURE_H_

#include "UIHelper.h"

#include <GL/gl.h>


class Texture
{
public:
	Texture(unsigned char * bitmap, Size newSize);
	~Texture();

	GLuint GLtexture;


private:
	Size size;

};

#endif // _TEXTURE_H_
