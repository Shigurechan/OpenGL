#ifndef ___TEST_HPP
#define ___TEST_HPP
#include <iostream>
#include <vector>
#include "Shape.hpp"

#include <glew/include/GL/glew.h>
//#include <glfw/include/GLFW/glfw3.h>



class Test
{
public:
	Test();
	~Test();

	void Update();
	void Draw();

private:







	GLuint CreateProgram(const char* vsrc, const char* fsrc);	//�v���O�����I�u�W�F�N�g���쐬
	GLboolean InfoLog(GLuint shader,const char *str);			//�G���[���O���擾
	bool ReadShaderSource(const char* name, std::vector<GLchar>& buffer);
	GLuint loadProgram(const char* vert, const char* frag);

	GLuint program;	//�v���O�����I�u�W�F�N�g�V�F�[�_�[

};

#endif

