#include "Window.hpp"

//�R���X�g���N�^
Window::Window(int width, int height, const char* title)
	:window(glfwCreateWindow(width, height, title, NULL, NULL))	
{
	std::fill(std::begin(keyBoard), std::end(keyBoard), 0);


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
	glfwSetKeyCallback(window, KeyBoard);		//�L�[�{�[�h�������ꂽ��
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

//�L�[����
void Window::KeyBoard(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	Window* const instance = (Window*)glfwGetWindowUserPointer(window);

	if (instance != NULL)
	{	
		if (instance->keyBoard[key] == 0 && action == GLFW_PRESS) {
			instance->keyBoard[key] = 1;
			printf("�������u��\n");
		}
		else if (instance->keyBoard[key] > 1 && action == GLFW_REPEAT) {
			instance->keyBoard[key] = 2;

			printf("�����Ă���Ƃ���\n");
		}
		else if (instance->keyBoard[key] != 0 && action == GLFW_RELEASE) {
			instance->keyBoard[key] = 0;

			printf("��������\n");
		}

	}
}
int Window::keyinput(int key)
{
	return keyBoard[key];
}







//�E�C���h�E�T�C�Y���擾
const glm::vec2 Window::getSize() const 
{
	return size;
}


//�L�[���͂��擾
const int Window::getKeyInput(int input)
{
	int key = glfwGetKey(window, input);

	if ( key == GLFW_PRESS)
	{
		keyBoard[key] += 1;
		if (keyBoard[key] > 1)
		{
			keyBoard[key] = 2;
		} 
	}
	else if (key == GLFW_RELEASE)
	{
		keyBoard[key] = 0;
	}

	return keyBoard[key];
}


//bool ���Z�q
Window::operator bool()
{
	glfwPollEvents();	//�C�x���g�����o��

	//�G���[����
	GLenum err;
	while ((err = glGetError()) != GL_NO_ERROR)
	{	
	//	std::cout <<"glGetError(): 0x"<< std::hex << err << std::endl;
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
