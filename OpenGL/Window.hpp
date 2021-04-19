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
	void SwapBuffers()const;	//ダブルバッファリング
	static void Resize(GLFWwindow* const window, int width, int height);	//サイズ変更
	const glm::vec2 getSize() const;
	GLfloat getScale() const;
	const glm::vec2 getLocation()const;
	static void Wheel(GLFWwindow* win, double x, double y);

	GLfloat scale;		//ワールド座標系に対するデバイス座標系の拡大率

private:

	GLFWwindow *const window;	//ウインドウコンテキスト

	glm::vec2 size;		//ウインドサイズ
	glm::vec2 location;	//図形の正規化デバイス座標上での位置


};

#endif

