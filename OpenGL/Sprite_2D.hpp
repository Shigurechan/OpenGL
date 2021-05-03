#ifndef ___Sprite_2D_HPP
#define ___Sprite_2D_HPP


#include <iostream>
#include <glew/include/GL/glew.h>
#include <glm/glm.hpp>

#include "Texture.hpp"
#include "Transform_2D.hpp"
#include "Shader.hpp"


class Window;
class Sprite_2D : protected Transform_2D,public Shader
{
public:

	Sprite_2D(std::shared_ptr<Window> w, const char* vert, const char* frag);		//�R���X�g���N�^
	~Sprite_2D();																	//�f�X�g���N�^

	virtual void Update();						//�X�V
	virtual void Draw(glm::mat4 projection);	//�`��

	// ###################### �����o�֐� ###################### 
	void setTexture(TextureData tex);			//�e�N�X�`���ݒ�
	void setDrawTextureID(unsigned char id);	//�`�悷��e�N�X�`���ԍ����w��

	void setPosition(const glm::vec2 p);		//�ړ�
	void setRotation(const float a);			//��]
	void setScaling(const glm::vec2 s);			//�X�P�[��


private:

	//���_�z��
	struct Vertex
	{
		GLfloat position[2];	//���W
		GLfloat uv[2];			//UV
	};



	std::vector<TextureData> textureID;	//�e�N�X�`���[ID
	int selectID;						//�e�N�X�`���[ID��I��
	GLuint vao;						//VertexArrayObject
	GLuint vbo;						//VertexBufferObject


	glm::vec2 Position;//
};

#endif
