#include "Sprite_2D.hpp"

#include <iostream>
#include <fstream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_Transform.hpp>
#include <glm/gtx/Transform.hpp>


#include "Shader.hpp"


//�R���X�g���N�^
Sprite_2D::Sprite_2D(std::shared_ptr<Window> w,const char* vert,const char* frag) : Transform_2D(w),Shader()
{
	//�V�F�[�_�[�ǂݍ���
	LoadShader(vert, frag);	
	selectID = -1;
	Position = glm::vec2(0,0);
	//���_���
	Vertex rectangleVertex[6] =
	{
		//���_�A���_�F
		{-0.5f,0.5f,     0.0f,1.0f},
		{-0.5f,-0.5f,	0.0f,0.0f},
		{0.5f,0.5f,		1.0f,1.0f},

		{0.5f,0.5f,		1.0f,1.0f},
		{-0.5f,-0.5f,    0.0f,0.0f},
		{0.5f,-0.5f,     1.0f,0.0f},


	};

	//vao
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	//vbo
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	//���_	
	GLint attrib = getAttribLocation("vertexPosition");
	glEnableVertexAttribArray(attrib);
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(Vertex), rectangleVertex, GL_STATIC_DRAW);
	glVertexAttribPointer(attrib, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)0);
	setBindAttribVertex("vertexPosition");

	attrib = getAttribLocation("vertexUV");
	glEnableVertexAttribArray(attrib);
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(Vertex), rectangleVertex, GL_STATIC_DRAW);
	glVertexAttribPointer(attrib, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)(sizeof(GLfloat) * 2));
	setBindAttribVertex("vertexUV");

	/*
	// �e�N�X�`��ID�̐���
	glGenTextures(1, &texID);

	// �t�@�C���̓ǂݍ���
	int x = 0;
	int y = 0;
	int channel = 0;
	unsigned char* fileData = stbi_load("texture.png",&x,&y,&channel,0);
	


	glBindTexture(GL_TEXTURE_2D, texID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 800, 800, 0, GL_RGBA, GL_UNSIGNED_BYTE, fileData);
	
	// �e�N�X�`���̐ݒ�
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	*/


	
	








	//�A���t�@�u�����h�L��
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//stbi_image_free(fileData);//�摜�f�[�^�J��



}


// ###################### �����o�֐� ###################### 

//�e�N�X�`���ݒ�
void Sprite_2D::setTexture(TextureData tex)
{
	
	textureID.push_back(tex);

	
	glGenTextures(1, &textureID.back().ID);	//�e�N�X�`��ID�̐���

	//�o�C���h
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glBindTexture(GL_TEXTURE_2D, textureID.back().ID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, textureID.back().size.x, textureID.back().size.y, 0, GL_RGBA, GL_UNSIGNED_BYTE, textureID.back().fileData);

	// �e�N�X�`���̕�Ԑݒ�
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	setSizeScale(glm::vec3(textureID.back().size.x, textureID.back().size.y, 1.0f));	//�X�v���C�g�T�C�Y��ݒ�

	//�����ōŌ�Ƀ��[�h���ăe�N�X�`����`�悷��悤�ɐݒ�
	glActiveTexture(textureID.back().ID);
	selectID++;

}

//�`�悷��e�N�X�`���ԍ����w��
void Sprite_2D::setDrawTextureID(unsigned char id)
{
	assert(id > textureID.size());

	glActiveTexture(textureID.at(id).ID);
}

//�ړ�
void Sprite_2D::setPosition(const glm::vec2 p)
{
	setTranslate(glm::vec3(p.x + (textureID.at(selectID).size.x / 2.0f),p.y + (textureID.at(selectID).size.y / 2.0f),0.0f));
}

//��]
void Sprite_2D::setRotation(const float a)
{
	setRotate(a);
}

//�X�P�[��
void Sprite_2D::setScaling(const glm::vec2 s)
{
	setScaling(glm::vec3(s.x,s.y,0.0f));
}



// ###################### ���t���[�� ###################### 

//�X�V
void Sprite_2D::Update()
{

}

//�`��
void Sprite_2D::Draw(glm::mat4 projection)
{	
	glBindVertexArray(vao);
	glBindTexture(GL_TEXTURE_2D, textureID.at(selectID).ID);
	

	setUniformMatrix4fv("uTranslate", translate);
	setUniformMatrix4fv("uRotate", rotate);
	setUniformMatrix4fv("uScale", scale);
	setUniformMatrix4fv("uViewProjection",projection);
	
	glDrawArrays(GL_TRIANGLES, 0, 6);

	
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);

}

//�f�X�g���N�^
Sprite_2D::~Sprite_2D()
{
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
}

