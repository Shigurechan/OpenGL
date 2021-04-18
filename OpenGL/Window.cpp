#include "Window.hpp"

Window::Window(int width, int height, const char* title)
	:window(glfwCreateWindow(width,height,title,NULL,NULL))
{
	if (window == NULL)
	{
		std::cerr << "�E�C���h�E�������s" << std::endl;
		exit(1);
	}

	glfwMakeContextCurrent(window);	//�R���e�L�X�g���쐬

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		std::cerr << "GLFW ���������s" << std::endl;
		exit(1);
	}

	atexit(glfwTerminate);	//�v���O�����I�����̏�����o�^
	glfwSwapInterval(1);	//��������

	glfwSetWindowUserPointer(window, this);	//���̃C���X�^���X��this

	glfwSetWindowSizeCallback(window, Resize);
	Resize(window, width, height);

}

//�T�C�Y�ύX
void Window::Resize(GLFWwindow* const window, int width, int height)
{
	int fbWidth, fbHeight;
	glfwGetFramebufferSize(window, &fbWidth, &fbHeight);
	glViewport(0, 0, fbWidth, fbHeight);

	Window* const instance = (Window*)glfwGetWindowUserPointer(window);

	if (instance != NULL)
	{
		instance->aspect = (GLfloat)width / (GLfloat)height;
	}
}

GLfloat Window::getAspect() const 
{
	return aspect;
}

Window::~Window()
{
	glfwDestroyWindow(window);
}


Window::operator bool()
{
	glfwWaitEvents();

	if (glfwWindowShouldClose(window) != 0)
	{
		return false;
	}
	else {
		return true;
	}	
}

//�_�u���o�b�t�@�����O
void Window::SwapBuffers()const
{
	glfwSwapBuffers(window);
}
