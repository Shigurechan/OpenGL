#include "Window.hpp"

Window::Window(int width, int height, const char* title)
	:window(glfwCreateWindow(width,height,title,NULL,NULL)),
	scale(100.0f),
	location{ 0.0f,0.0f }

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

	glfwSetWindowSizeCallback(window, Resize);	//�E�C���h�E�T�C�Y��ύX���鎞�ɌĂяo������
	glfwSetScrollCallback(window,Wheel);		//�}�E�X�z�C�[�����쎞�ɌĂяo������

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
		instance->size[0] = (GLfloat)width;
		instance->size[1] = (GLfloat)height;
	}
}

const glm::vec2 Window::getSize() const 
{
	return size;
}

GLfloat Window::getScale() const
{
	return scale;
}

const glm::vec2 Window::getLocation()const
{
	return location;
}


Window::~Window()
{
	glfwDestroyWindow(window);
}

void Window::Wheel(GLFWwindow* win, double x, double y)
{
	Window* const instance = (Window*)glfwGetWindowUserPointer(win);

	if (instance != NULL)
	{
		instance->scale += (GLfloat)y;
	}
}

Window::operator bool()
{
	glfwWaitEvents();	//�C�x���g�����o��







	//�}�E�X���N���b�N�����Ƃ�
	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_1) != GLFW_RELEASE)
	{
		//�}�E�X�J�[�\���̍��W���擾
		double x, y;
		glfwGetCursorPos(window, &x, &y);

		//�}�E�X�J�[�\���̐��K���f�o�C�X���W�n��ł̍��W�����߂�
		location.x = (GLfloat)x * 2.0f / size.x - 1.0f;
		location.y = 1.0f - (GLfloat)y * 2.0f / size.y;

//		printf("x: %f\n", location.x);
//		printf("y: %f\n\n", location.y);

	}

	//ESC�L�[���������狭���I��
	if (glfwGetKey(window, GLFW_KEY_ESCAPE))
	{
		return false;
	}

	//�E�C���h�E�����K�v������� false
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
