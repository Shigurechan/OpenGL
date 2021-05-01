#ifndef ___Sprite_2D_HPP
#define ___Sprite_2D_HPP


#include <iostream>
#include <glew/include/GL/glew.h>
#include <glm/glm.hpp>

#include "Transform.hpp"

class Shader;
class Window;

class Sprite_2D : public Transform
{
public:

	//���_�z��
	struct Vertex
	{
		GLfloat position[2];
	};



	Sprite_2D(std::shared_ptr<Window> w);		//�R���X�g���N�^
	~Sprite_2D();								//�f�X�g���N�^

	virtual void Update();						//�X�V
	virtual void Draw(glm::mat4 projection);	//�`��

private:

	std::shared_ptr<Shader> shader;	//�V�F�[�_�[�N���X



	GLuint vao;	//VertexArrayObject
	GLuint vbo;	//VertexBufferObject


};

#endif
