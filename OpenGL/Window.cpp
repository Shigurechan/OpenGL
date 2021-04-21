#include "Window.hpp"

//コンストラクタ
Window::Window(int width, int height, const char* title)
	:window(glfwCreateWindow(width, height, title, NULL, NULL))	
{

	//初期化
	//std::fill(std::begin(keyStatus),std::end(keyStatus),0);
	//wheel = 0;

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


	//イベント処理
	glfwSetWindowUserPointer(window, this);		//このインスタンスのthis
	glfwSetWindowSizeCallback(window, Resize);	//ウインドウサイズを変更する時に呼び出す処理
	
	Resize(window, width, height);	//リサイズ

}

//サイズ変更
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

//ウインドウサイズを取得
const glm::vec2 Window::getSize() const 
{
	return size;
}


//キー入力を取得
const int Window::getKeyInput(int key)const
{
	return 0;//keyStatus[key];
}


//bool 演算子
Window::operator bool()
{
	glfwPollEvents();	//イベントを取り出す

	//エラー処理
	GLenum err;
	while ((err = glGetError()) != GL_NO_ERROR)
	{	
		std::cout <<"glGetError(): 0x"<< std::hex << err << std::endl;
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

//デストラクタ
Window::~Window()
{
	glfwDestroyWindow(window);
}
