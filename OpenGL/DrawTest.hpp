#ifndef ___DRAWTEST_HPP
#define ___DRAWTEST_HPP

#include <iostream>
#include <glew/include/GL/glew.h>

class DrawTest
{
public:
	DrawTest();		//�R���X�g���N�^
	~DrawTest();	//�f�X�g���N�^

	void Update();	//�X�V
	void Draw();	//�`��

private:
	

	GLuint vao;	//VertexArrayObject
	GLuint vbo;	//VertexBufferObject


};

#endif
