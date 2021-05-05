#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <glew/include/GL/glew.h>
#include <glfw/include/GLFW/glfw3.h>

#include "Window.hpp"

#include "Sprite_2D.hpp"
#include "Camera.hpp"
#include "Texture.hpp"


int main()
{
	if (glfwInit() == GL_FALSE)
	{
		std::cerr << "glfw初期化失敗。" << std::endl;
		return -1;
	}

	atexit(glfwTerminate);	//プログラム終了時の処理を登録
	std::shared_ptr<Window> window = std::make_shared<Window>();			//コンテキストを作成
	
	//OpenGL Verison 3.2 Core Profile　を選択する
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,5);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

// #############################################################################






	Sprite_2D sprite(window);	//表示オブジェクト

	sprite.setTexture(LoadTexture("texture_1.png"));
	sprite.setTexture(LoadTexture("texture_2.png"));
	

	
	glm::vec2 pos = glm::vec2(0, 0);
	glm::vec2 scale = glm::vec2(0,0);
	float angle = 0.0f;

	while (*window)
	{
		glClearColor(0.0, 0.0, 1.0, 1.0);					//カラーバッファのクリア色を設定
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	//カラーバッファ指定色でクリア
		


		if (window->getKeyInput(GLFW_KEY_D) > 0)
		{
			pos.x += 10;
		}else if (window->getKeyInput(GLFW_KEY_A) > 0)
		{
			pos.x += -10;

		}else if (window->getKeyInput(GLFW_KEY_W) > 0)
		{
			pos.y += -10;

		}
		else if (window->getKeyInput(GLFW_KEY_S) > 0)
		{
			pos.y += 10;

		}else if (window->getKeyInput(GLFW_KEY_Q) > 0)
		{
			angle += 10;
		}
		else if (window->getKeyInput(GLFW_KEY_E) > 0)
		{
			angle += -10;

		}
		else if (window->getKeyInput(GLFW_KEY_Z) > 0)
		{
			scale.x += 10;
		}
		else if (window->getKeyInput(GLFW_KEY_X) > 0)
		{
			scale.x += -10;

		}
		else if (window->getKeyInput(GLFW_KEY_C) > 0)
		{
			scale.y += 10;
		}
		else if (window->getKeyInput(GLFW_KEY_V) > 0)
		{
			scale.y += -10;

		}	

		sprite.setEnable();
		
	
		//sprite.setUniform4f("uFragment", glm::vec4(0.0, 0.0, 1.0, 1.0));

		sprite.DrawGraph(pos,0);
		//sprite.DrawRotateGraph(pos, angle,1);
		//sprite.DrawExtendGraph(pos,scale,0);
	



		sprite.setDisable();


		window->SwapBuffers();	//ダブルバッファリング
	}

}
