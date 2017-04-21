#ifndef _TEXTURE_HELPER_H_
#define _TEXTURE_HELPER_H_

#include "UIHelper.h"

#include <GL/glut.h>


class TextureHelper
{
public:
	static GLuint loadTexture(unsigned char * buffer, Size size, bool smoothTexture);
};

#endif // _TEXTURE_HELPER_H_
