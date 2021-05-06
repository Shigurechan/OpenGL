#include "Sprite.hpp"

#include <iostream>
#include <fstream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_Transform.hpp>
#include <glm/gtx/Transform.hpp>


#include "Shader.hpp"
#include "Window.hpp"


//"Shader/BasicTexture_2D.vert", "Shader/BasicTexture_2D.frag"
//�R���X�g���N�^
Sprite::Sprite(std::shared_ptr<Window> w,const char* vert,const char* frag) : Transform_2D(),Shader()
{
	windowContext = w;	//�E�C���h�E�R���e�L�X�g


	//�V�F�[�_�[�ǂݍ���

	if (vert == NULL && frag == NULL)
	{
		vert = "Shader/2D/BasicTexture_2D.vert";
		frag = "Shader/2D/BasicTexture_2D.frag";
		isDefaultShader = true;
	}
	else 
	{
		LoadShader(vert, frag);

		isDefaultShader = false;

	}

	LoadShader(vert, frag);	//�V�F�[�_�[���[�h
	

	//�e�N�X�`���֌W
	textureNumber = 0;
	textureID = std::vector<TextureData>();
	textureUnitCount = 0;

	
	//vao
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	//vbo
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	//���_	
	GLint attrib = getAttribLocation("vertexPosition");
	glEnableVertexAttribArray(attrib);
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(VertexUV), rectangleVertex, GL_STATIC_DRAW);
	glVertexAttribPointer(attrib, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)0);
	setBindAttribVertex("vertexPosition");

	attrib = getAttribLocation("vertexUV");
	glEnableVertexAttribArray(attrib);
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(VertexUV), rectangleVertex, GL_STATIC_DRAW);
	glVertexAttribPointer(attrib, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)(sizeof(GLfloat) * 2));
	setBindAttribVertex("vertexUV");


	//�A���t�@�u�����h�L��
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}


// ###################### �����o�֐� ###################### 

//�e�N�X�`���ݒ�
void Sprite::setTexture(TextureData tex)
{
	
	textureID.push_back(tex);	//�e�N�X�`���[ID�ɒǉ�

	
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


	textureID.back().textureNumber = GL_TEXTURE0 + textureUnitCount;
	assert(textureID.back().textureNumber < GL_TEXTURE31);//�G���[�\��

	textureUnitCount++;	//�e�N�X�`���[���j�b�g�J�E���g�ɉ��Z
}

//�`�悷��e�N�X�`���ԍ����w��
void Sprite::setDrawTextureID(unsigned char id)
{
	assert(id < textureID.size());
	glActiveTexture(textureID.at(id).textureNumber);
	textureNumber = textureID.at(id).textureNumber;
}

//�`��
void Sprite::DrawGraph(glm::vec2 pos, unsigned char texNum)
{
	if (isDefaultShader == true)
	{
		setEnable();
	}

	setDrawTextureID((unsigned char)texNum);	//�e�N�`���[���j�b�g��ݒ�
	glBindVertexArray(vao);
	glBindTexture(GL_TEXTURE_2D, textureID.at(texNum).ID);
	


	setTranslate(glm::vec3(pos.x + (textureID.at(texNum).size.x / 2.0f), pos.y + (textureID.at(texNum).size.y / 2.0f), 0.0f));	//���s�ړ�

	//uniform
	setUniformMatrix4fv("uTranslate", translate);
	setUniformMatrix4fv("uRotate", rotate);
	setUniformMatrix4fv("uScale", scale);
	setUniformMatrix4fv("uViewProjection", glm::ortho(0.0f, windowContext->getSize().x, windowContext->getSize().y, 0.0f, -1.0f, 1.0f));
	
	glDrawArrays(GL_TRIANGLES, 0, 6);

	
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);

	if (isDefaultShader == true)
	{
		setDisable();
	}

}

//��]�`��
void Sprite::DrawRotateGraph(glm::vec2 pos, float angle,unsigned char texNum)
{
	if (isDefaultShader == true)
	{
		setEnable();
	}

	glBindVertexArray(vao);
	glBindTexture(GL_TEXTURE_2D, textureID.at(texNum).ID);

	setRotate(angle);	//��]
	setTranslate(glm::vec3(pos.x + (textureID.at(texNum).size.x / 2.0f), pos.y + (textureID.at(texNum).size.y / 2.0f), 0.0f));	//���s�ړ�

	//uniform
	setUniformMatrix4fv("uTranslate", translate);
	setUniformMatrix4fv("uRotate", rotate);
	setUniformMatrix4fv("uScale", scale);
	setUniformMatrix4fv("uViewProjection", glm::ortho(0.0f, windowContext->getSize().x, windowContext->getSize().y, 0.0f, -1.0f, 1.0f));

	glDrawArrays(GL_TRIANGLES, 0, 6);

	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);


	if (isDefaultShader == true)
	{
		setDisable();
	}

}

//�X�P�[���`��
void Sprite::DrawExtendGraph(glm::vec2 pos, glm::vec2 s,unsigned char texNum)
{
	if (isDefaultShader == true)
	{
		setEnable();
	}

	glBindVertexArray(vao);
	glBindTexture(GL_TEXTURE_2D, textureID.at(texNum).ID);

	setScale(s);	//�X�P�[��
	setTranslate(glm::vec3(pos.x + (textureID.at(texNum).size.x / 2.0f), pos.y + (textureID.at(texNum).size.y / 2.0f), 0.0f));	//���s�ړ�

	//Uniform
	setUniformMatrix4fv("uTranslate", translate);
	setUniformMatrix4fv("uRotate", rotate);
	setUniformMatrix4fv("uScale", scale);
	setUniformMatrix4fv("uViewProjection", glm::ortho(0.0f, windowContext->getSize().x, windowContext->getSize().y, 0.0f, -1.0f, 1.0f));


	glDrawArrays(GL_TRIANGLES, 0, 6);

	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);

	if (isDefaultShader == true)
	{
		setDisable();
	}

}



//�f�X�g���N�^
Sprite::~Sprite()
{
	//�e�N�X�`���[ID���J��
	for (int i = 0; i < textureID.size(); i++)
	{
		glDeleteTextures(1,&textureID.at(i).ID);
		delete[] textureID.at(i).fileData;
		textureID.at(i).fileData = NULL;
	}

	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
}

