#ifndef ___Sprite_2D_HPP
#define ___Sprite_2D_HPP


#include <iostream>
#include <glew/include/GL/glew.h>
#include <glm/glm.hpp>

#include "Transform_2D.hpp"
#include "Shader.hpp"


class Window;




class Sprite_2D : public Transform_2D,public Shader
{
public:

	//���_�z��
	struct Vertex
	{
		GLfloat position[2];	//���W
		GLfloat uv[2];			//UV
	};



	Sprite_2D(std::shared_ptr<Window> w, const char* vert, const char* frag);		//�R���X�g���N�^
	~Sprite_2D();																	//�f�X�g���N�^

	virtual void Update();						//�X�V
	virtual void Draw(glm::mat4 projection);	//�`��

private:

	



	GLuint vao;	//VertexArrayObject
	GLuint vbo;	//VertexBufferObject


};

#endif
