#ifndef ___SHADER_HPP
#define ___SHADER_HPP

#include <iostream>
#include <vector>
#include "glm/glm.hpp"


#include <glew/include/GL/glew.h>
//#include <glfw/include/GLFW/glfw3.h>



class Shader
{
public:
	Shader(const char* vert,const char* frag);	//�R���X�g���N�^
	~Shader();	//�f�X�g���N�^

	void Active();	//�L���ɂ���B
	void setBindAttribVertex(int num, const char* str);		//���_�V�F�[�_�[�ɑ����ϐ����֘A������
	void setBindAttribFragment(int num,const char* str);	//�t���O�����g�V�F�[�_�[�ɑ����ϐ����֘A������

	void setUniform2fv(const char* name, const glm::vec2 vec);
	void setUniform1f(const char* name,const float vec);

private:

	GLuint CreateProgram(const char* vsrc, const char* fsrc);				//�v���O�����I�u�W�F�N�g���쐬
	GLboolean InfoLog(GLuint shader,const char *str);						//�G���[���O���擾
	bool ReadShaderSource(const char* name, std::vector<GLchar>& buffer);	//�\�[�X�t�@�C����ǂݍ���
	GLuint loadProgram(const char* vert, const char* frag);					//�v���O�������I�u�W�F�N�g�����[�h

	GLuint program;	//�v���O�����I�u�W�F�N�g�V�F�[�_�[

};

#endif

