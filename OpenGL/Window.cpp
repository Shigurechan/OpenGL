#include "Window.hpp"

Window::Window(int width, int height, const char* title)
	:window(glfwCreateWindow(width,height,title,NULL,NULL)),
	scale(100.0f),
	location{ 0.0f,0.0f }

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

	glfwSetWindowSizeCallback(window, Resize);	//ウインドウサイズを変更する時に呼び出す処理
	glfwSetScrollCallback(window,Wheel);		//マウスホイール操作時に呼び出す処理

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
	glfwWaitEvents();	//イベントを取り出す







	//マウスをクリックしたとき
	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_1) != GLFW_RELEASE)
	{
		//マウスカーソルの座標を取得
		double x, y;
		glfwGetCursorPos(window, &x, &y);

		//マウスカーソルの正規化デバイス座標系上での座標を求める
		location.x = (GLfloat)x * 2.0f / size.x - 1.0f;
		location.y = 1.0f - (GLfloat)y * 2.0f / size.y;

//		printf("x: %f\n", location.x);
//		printf("y: %f\n\n", location.y);

	}

	//ESCキーを押したら強制終了
	if (glfwGetKey(window, GLFW_KEY_ESCAPE))
	{
		return false;
	}

	//ウインドウを閉じる必要があれば false
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
