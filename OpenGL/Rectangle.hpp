#ifndef ___RECTANGLE_HPP
#define ___RECTANGLE_HPP

#include <iostream>
#include "glm/glm.hpp"

#include "Transform_2D.hpp"
#include "Shader.hpp"
#include "Sprite.hpp"

/*#########################################################################
# 矩形描画クラス
###########################################################################*/

namespace FrameWork
{
	class Window;

	class Rectangle : protected FrameWork::Transform_2D, public Shader
	{

	public:

		//frag 頂点色描画をするかどうか？
		Rectangle(std::shared_ptr<Window> w, const char* vert = NULL, const char* frag = NULL);										//コンストラクタ
		~Rectangle();																									//デストラクタ


		void Draw(glm::vec2 start, glm::vec2 end, glm::vec4 color);																	// 描画
		void DrawRotate(glm::vec2 start, glm::vec2 end, float angle, glm::vec4 color);												// 回転 描画

		void DrawColor(glm::vec2 start, glm::vec2 end, glm::vec4 lu, glm::vec4 ru, glm::vec4 rd, glm::vec4 ld);						// 頂点色描画
		void DrawRotateColor(glm::vec2 start, glm::vec2 end, float angle, glm::vec4 lu, glm::vec4 ru, glm::vec4 rd, glm::vec4 ld);	// 回転 頂点色描画


	private:

		//塗りつぶし矩形
		Transform_2D::VertexColor rectangleVertex[6] =
		{
			//頂点、頂点色
			{-0.5f,0.5f,    0.0f,1.0f,0.0f,1.0f},
			{-0.5f,-0.5f,	0.0f,1.0f,0.0f,1.0f},
			{0.5f,0.5f,		0.0f,1.0f,0.0f,1.0f},

			{0.5f,0.5f,		 0.0f,1.0f,0.0f,1.0f},
			{-0.5f,-0.5f,    0.0f,1.0f,0.0f,1.0f},
			{0.5f,-0.5f,     0.0f,1.0f,0.0f,1.0f},
		};


		void setVertexALLColor(glm::vec4 color);			//頂点カラーを全部設定
		void setVertexColor(int vertNum, glm::vec4 color);	//頂点カラーを一つ設定

		bool vertexColorFrag;


		std::shared_ptr<Window> windowContext;	//ウインドウコンテキスト

	};
}


#endif

