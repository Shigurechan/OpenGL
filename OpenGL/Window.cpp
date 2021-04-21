#include "Window.hpp"

//�R���X�g���N�^
Window::Window(int width, int height, const char* title)
	:window(glfwCreateWindow(width, height, title, NULL, NULL))	
{

	//������
	//std::fill(std::begin(keyStatus),std::end(keyStatus),0);
	//wheel = 0;

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


	//�C�x���g����
	glfwSetWindowUserPointer(window, this);		//���̃C���X�^���X��this
	glfwSetWindowSizeCallback(window, Resize);	//�E�C���h�E�T�C�Y��ύX���鎞�ɌĂяo������
	
	Resize(window, width, height);	//���T�C�Y

}

//�T�C�Y�ύX
void Window::Resize(GLFWwindow* const win, int width, int height)
{
	int fbWidth, fbHeight;
	glfwGetFramebufferSize(win, &fbWidth, &fbHeight);
	glViewport(0, 0, fbWidth, fbHeight);

	Window* const instance = (Window*)glfwGetWindowUserPointer(win);

	if (instance != NULL)
	{
		instance->size.x = (GLfloat)width;
		instance->size.y = (GLfloat)height;		
	}
}

//�E�C���h�E�T�C�Y���擾
const glm::vec2 Window::getSize() const 
{
	return size;
}


//�L�[���͂��擾
const int Window::getKeyInput(int key)const
{
	return 0;//keyStatus[key];
}


//bool ���Z�q
Window::operator bool()
{
	glfwPollEvents();	//�C�x���g�����o��

	//�G���[����
	GLenum err;
	while ((err = glGetError()) != GL_NO_ERROR)
	{	
		std::cout <<"glGetError(): 0x"<< std::hex << err << std::endl;
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

//�f�X�g���N�^
Window::~Window()
{
	glfwDestroyWindow(window);
}
