//#define GLEW_STATIC	//�X�^�e�B�b�N�����N
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <glew/include/GL/glew.h>
#include <glfw/include/GLFW/glfw3.h>

#include "Window.hpp"
#include "Shader.hpp"
#include "DrawTest.hpp"


int main()
{
	if (glfwInit() == GL_FALSE)
	{
		std::cerr << "glfw���������s�B" << std::endl;
		return -1;
	}

	atexit(glfwTerminate);	//�v���O�����I�����̏�����o�^
	Window window;			//�R���e�L�X�g���쐬

	//OpenGL Verison 3.2 Core Profile�@��I������
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

	glClearColor(1.0, 0.0, 0.0, 1.0);	//�w�i�F
// #############################################################################


	DrawTest test;	//�\���I�u�W�F�N�g

	Shader shader("Test.vert","Test.frag");

	//shader.setBindAttribVertex("position");

	//shader.setBindAttribVertex("fragment");

	//shader.setBindAttribFragment("out_fragment");

	//shader.setUniform4fv();
	while (window)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	//�J���[�o�b�t�@���N���A
		shader.Active();
		
		test.Draw();
		
		//std::cout << "��������: " << window.getKeyInput(GLFW_KEY_SPACE) << std::endl;
		std::cout << "��������: " << window.keyinput(GLFW_KEY_SPACE) << std::endl;
		





		window.SwapBuffers();	//�_�u���o�b�t�@�����O
	}

}
