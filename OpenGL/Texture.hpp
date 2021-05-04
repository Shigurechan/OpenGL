#ifndef ___TEXTURE_HPP_
#define ___TEXTURE_HPP_

#include <iostream>
#include "glm/glm.hpp"
#include "glew/include/GL/glew.h"

typedef struct
{
	glm::ivec2 size;
	unsigned char *fileData;
	int channel;
	GLuint ID;
	GLuint textureNumber;
}TextureData;

TextureData LoadTexture(const char* fileName);	//テクスチャーロード


#endif