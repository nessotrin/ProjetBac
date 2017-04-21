#ifndef _GLOBAL_TEXTURE_H_
#define _GLOBAL_TEXTURE_H_

#include "Texture.h"

class GlobalTexture
{
public:

	static bool load();
	
	static Texture plusTexture;
	static Texture plusTextureActive;

	static Texture minusTexture;
	static Texture minusTextureActive;
	

};

#endif // _GLOBAL_TEXTURE_H_
