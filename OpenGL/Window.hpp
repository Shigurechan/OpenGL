#ifndef ___WINDOW_HPP
#define ___WINDOW_HPP

#include <iostream>
#include <glew/include/GL/glew.h>
#include <glfw/include/GLFW/glfw3.h>
#include "glm/glm.hpp"


class Window
{
public:

	Window(int width = 640, int height = 480, const char* title = "Hello!");	//コンストラクタ
	virtual ~Window();															//デストラクタ

	explicit operator bool();	//bool 演算子
	void SwapBuffers()const;	//ダブルバッファリング

	

	//イベント処理
	static void Resize(GLFWwindow* const win, int width, int height);						//サイズ変更
	

	const glm::vec2 getSize() const;		//サイズを取得
	const int getKeyInput(int key)const;	//キー入力を取得

private:

	GLFWwindow *const window;	//ウインドウコンテキスト

	
	glm::vec2 size;				//ウインドサイズ
	
};

#endif

