#include "Window.hpp"

Window::Window(int width, int height, const char* title)
	:window(glfwCreateWindow(width,height,title,NULL,NULL))
{
	if (window == NULL)
	{
		std::cerr << "ウインドウ生成失敗" << std::endl;
		exit(1);
	}

	glfwMakeContextCurrent(window);	//コンテキストを作成

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		std::cerr << "GLFW 初期化失敗" << std::endl;
		exit(1);
	}

	atexit(glfwTerminate);	//プログラム終了時の処理を登録
	glfwSwapInterval(1);	//垂直同期

	glfwSetWindowUserPointer(window, this);	//このインスタンスのthis

	glfwSetWindowSizeCallback(window, Resize);
	Resize(window, width, height);

}

//サイズ変更
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

//ダブルバッファリング
void Window::SwapBuffers()const
{
	glfwSwapBuffers(window);
}
