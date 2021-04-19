#ifndef ___WINDOW_HPP
#define ___WINDOW_HPP

#include <iostream>
#include <glew/include/GL/glew.h>
#include <glfw/include/GLFW/glfw3.h>
#include "glm/glm.hpp"


class Window
{
public:
	Window(int width = 640, int height = 480, const char* title = "Hello!");
	virtual ~Window();

	explicit operator bool();
	void SwapBuffers()const;	//�_�u���o�b�t�@�����O
	static void Resize(GLFWwindow* const window, int width, int height);	//�T�C�Y�ύX
	const glm::vec2 getSize() const;
	GLfloat getScale() const;
	const glm::vec2 getLocation()const;
	static void Wheel(GLFWwindow* win, double x, double y);

	GLfloat scale;		//���[���h���W�n�ɑ΂���f�o�C�X���W�n�̊g�嗦

private:

	GLFWwindow *const window;	//�E�C���h�E�R���e�L�X�g

	glm::vec2 size;		//�E�C���h�T�C�Y
	glm::vec2 location;	//�}�`�̐��K���f�o�C�X���W��ł̈ʒu


};

#endif

