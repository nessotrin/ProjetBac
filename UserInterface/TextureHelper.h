#ifndef _TEXTURE_HELPER_H_
#define _TEXTURE_HELPER_H_

#include "UIHelper.h"

#ifndef BBB
#include <GL/gl.h>
#else
#include <GLES2/gl2.h>
#endif


class TextureHelper
{
public:
	static GLuint loadTexture(unsigned char * buffer, Size size, bool smoothTexture);
};

#endif // _TEXTURE_HELPER_H_
