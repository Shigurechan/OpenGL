#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <glew/include/GL/glew.h>
#include <glfw/include/GLFW/glfw3.h>

#include "Window.hpp"

#include "Sprite_2D.hpp"
#include "Camera.hpp"
#include "Texture.hpp"


int main()
{
	if (glfwInit() == GL_FALSE)
	{
		std::cerr << "glfw���������s�B" << std::endl;
		return -1;
	}

	atexit(glfwTerminate);	//�v���O�����I�����̏�����o�^
	std::shared_ptr<Window> window = std::make_shared<Window>();			//�R���e�L�X�g���쐬
	std::shared_ptr<Camera> camera = std::make_shared<Camera>(window);			//�J�������쐬


	//OpenGL Verison 3.2 Core Profile�@��I������
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,5);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

	glClearColor(0.0, 0.0, 1.0, 1.0);	//�w�i�F
// #############################################################################






	Sprite_2D sprite(window,"Shader/BasicTexture_2D.vert","Shader/BasicTexture_2D.frag");	//�\���I�u�W�F�N�g
	sprite.setTexture(LoadTexture("texture.png"));
	//sprite.Load("Shader/BasicMono_2D.vert", "Shader/BasicMono_2D.frag");
	

	
	glm::vec2 pos = glm::vec2(0,0);

	while (*window)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	//�J���[�o�b�t�@���N���A
		


		if (window->getKeyInput(GLFW_KEY_D) > 0)
		{
			pos.x += 100;
		}else if (window->getKeyInput(GLFW_KEY_A) > 0)
		{
			pos.x += -100;

		}else if (window->getKeyInput(GLFW_KEY_W) > 0)
		{
			pos.y += -100;

		}
		else if (window->getKeyInput(GLFW_KEY_S) > 0)
		{
			pos.y += 100;

		}






		sprite.setPosition(pos);

		sprite.setEnable();


		

		sprite.Update();

		sprite.setUniform4f("uFragment", glm::vec4(0.0, 0.0, 1.0, 1.0));

		sprite.Draw(camera->getProjection_2D());
	



		sprite.setDisable();


		window->SwapBuffers();	//�_�u���o�b�t�@�����O
	}

}
