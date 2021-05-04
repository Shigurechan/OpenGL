#include "Texture.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>




TextureData LoadTexture(const char* fileName)
{
	TextureData data;
	data.fileData = NULL;
	data.fileData = stbi_load(fileName, &data.size.x, &data.size.y, &data.channel, 0);
	
	assert(data.fileData);
	
	return data;
}
