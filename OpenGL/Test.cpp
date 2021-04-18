#include "Test.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
Test::Test()
{

}

//�V�F�[�_�[�����[�h
GLuint Test::loadProgram(const char* vert, const char* frag)
{
	std::vector<GLchar> vsrc;
	const bool vstat = ReadShaderSource(vert, vsrc);

	std::vector<GLchar> fsrc;
	const bool fstat = ReadShaderSource(frag, fsrc);


	if (vstat && fstat)
	{
		return CreateProgram(vsrc.data(), fsrc.data());
	}
	else {
		return 0;
	}
}



//�V�F�[�_�[�t�@�C����ǂݍ���
bool Test::ReadShaderSource(const char* name, std::vector<GLchar>& buffer)
{
	if (name == NULL)
	{
		return false;
	}
	

	std::ifstream file(name, std::ios::binary);
	if (file.fail())
	{
		std::cerr << "�\�[�X�t�@�C�����ǂݍ��߂܂���: " << name << std::endl;
		return false;
	}

	file.seekg(0L, std::ios::end);
	GLsizei length = static_cast<GLsizei>(file.tellg());
	buffer.resize(length + 1);
	file.seekg(0L, std::ios::beg);
	buffer[length] = '\0';

	if (file.fail())
	{
		std::cerr << "�\�[�X�t�@�C����ǂݍ��߂܂���: " << name << std::endl;
		file.close();

		return false;
	}

	file.close();
	return true;
}



//�G���[���O���擾
GLboolean Test::InfoLog(GLuint shader, const char* str)
{
	GLint status;

	//�R���p�C������
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
	if (status == GL_FALSE)
	{
		std::cerr << "�R���p�C���G���[�@" << str << std::endl;
	}
	
	//�G���[���O�̒����𓾂�
	GLsizei bufSize;
	glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &bufSize);

	if (bufSize > 1)
	{
		std::vector<GLchar> infoLog(bufSize);
		GLsizei length;
		glGetShaderInfoLog(shader, bufSize, &length, &infoLog[0]);

		std::cerr<< &infoLog[0] << std::endl;
	}



	return (GLboolean)status;
}




//�v���O�����I�u�W�F�N�g�쐬
GLuint Test::CreateProgram(const char* vsrc, const char* fsrc)
{
	const GLuint program(glCreateProgram());
	if (vsrc != NULL)
	{
		const GLuint vobj(glCreateShader(GL_VERTEX_SHADER));
		glShaderSource(vobj, 1, &vsrc, NULL);
		glCompileShader(vobj);

		InfoLog(vobj, vsrc);

		glAttachShader(program, vobj);
		glDeleteShader(vobj);

	}
	else {
		std::cout << "���_�V�F�[�_�[�ǂݍ��ݎ��s" << std::endl;
	}

	if (fsrc != NULL)
	{
		const GLuint fobj(glCreateShader(GL_VERTEX_SHADER));
		glShaderSource(fobj, 1, &fsrc, NULL);
		glCompileShader(fobj);

		InfoLog(fobj, "fsrc");

		glAttachShader(program, fobj);
		glDeleteShader(fobj);
	}
	else {
		//std::cout << "�t���O�����g�V�F�[�_�[�ǂݍ��ݎ��s" << std::endl;

	}


	glBindAttribLocation(program, 0, "Position");
	glBindFragDataLocation(program, 0, "fragment");
	glLinkProgram(program);


	return program;
}

void Test::Update()
{

}




void Test::Draw() 
{
	
	
}











Test::~Test()
{

}
