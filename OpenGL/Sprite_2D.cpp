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
	Load(vert, frag);	

	
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




	// �e�N�X�`��ID�̐���
	GLuint texID;
	glGenTextures(1, &texID);

	// �t�@�C���̓ǂݍ���
	std::ifstream fstr("texture.png", std::ios::binary);
	if (fstr.is_open() == true) {
		const size_t fileSize = static_cast<size_t>(fstr.seekg(0, fstr.end).tellg());
		fstr.seekg(0, fstr.beg);
		char* textureBuffer = new char[fileSize];
		fstr.read(textureBuffer, fileSize);
		fstr.seekg(0, fstr.beg);

		//printf("��������");
		// �e�N�X�`����GPU�ɓ]��
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glBindTexture(GL_TEXTURE_2D, texID);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 256, 256, 0, GL_RGB, GL_UNSIGNED_BYTE, textureBuffer);

		// �e�N�X�`���̐ݒ�
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		// �e�N�X�`���̃A���o�C���h
		delete[] textureBuffer;
		glBindTexture(GL_TEXTURE_2D, 0);
	}
	else {
		std::cerr << "�t�@�C�����J���܂���" << std::endl;
	}




	
}

//�X�V
void Sprite_2D::Update()
{

}

//�`��
void Sprite_2D::Draw(glm::mat4 projection)
{
	//setEnable();
	glBindVertexArray(vao);

	setUniformMatrix4fv("uTranslate", translate);
	setUniformMatrix4fv("uRotate", rotate);
	setUniformMatrix4fv("uScale", scale);
	setUniformMatrix4fv("uViewProjection",projection);
	
	glDrawArrays(GL_TRIANGLES, 0, 6);

	//setDisable();
	glBindVertexArray(0);

}

//�f�X�g���N�^
Sprite_2D::~Sprite_2D()
{
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
}

