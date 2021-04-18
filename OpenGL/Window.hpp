#ifndef ___WINDOW_HPP
#define ___WINDOW_HPP

#include <iostream>
#include <glew/include/GL/glew.h>
#include <glfw/include/GLFW/glfw3.h>


class Window
{
public:
	Window(int width = 640, int height = 480, const char* title = "Hello!");
	virtual ~Window();

	explicit operator bool();
	void SwapBuffers()const;	//�_�u���o�b�t�@�����O
	static void Resize(GLFWwindow* const window, int width, int height);	//�T�C�Y�ύX
	GLfloat getAspect() const;
private:

	GLFWwindow *const window;	//�E�C���h�E�R���e�L�X�g
	GLfloat aspect;	//�A�X�y�N�g��
};

#endif

