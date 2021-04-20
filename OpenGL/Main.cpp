//#define GLEW_STATIC	//スタティックリンク
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <glew/include/GL/glew.h>
#include <glfw/include/GLFW/glfw3.h>

#include "Window.hpp"
#include "Shader.hpp"
#include "DrawTest.hpp"


int main()
{
	if (glfwInit() == GL_FALSE)
	{
		std::cerr << "glfw初期化失敗。" << std::endl;
		return -1;
	}

	atexit(glfwTerminate);	//プログラム終了時の処理を登録
	Window window;			//コンテキストを作成

	//OpenGL Verison 3.2 Core Profile　を選択する
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,2);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

	glClearColor(1.0, 0.0, 0.0, 1.0);	//背景色
// #############################################################################

	DrawTest test;


	Shader shader("Test.vert","Test.frag");

	shader.setBindAttribVertex(0, "Position");
	shader.setBindAttribVertex(1, "fragColor");

	shader.setBindAttribFragment(0, "fragment");


	while (window)
	{
		glClear(GL_COLOR_BUFFER_BIT);	//カラーバッファをクリア
		shader.Active();
		
		test.Draw();
		

		





		window.SwapBuffers();	//ダブルバッファリング
	}

}
