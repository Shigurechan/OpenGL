#include "DrawTest.hpp"

#include <iostream>
#include "Shader.hpp"
#include <glm/gtx/matrix_transform_2d.hpp>
#include <glm/glm.hpp>

//コンストラクタ
DrawTest::DrawTest()
{
	shader = std::make_shared<Shader>("Basic_2D.vert","Basic_2D.frag");	//シェーダー

	//頂点配列
	struct Vertex
	{
		GLfloat position[2];
	//	GLfloat color[4];
	};

	//頂点情報
	Vertex rectangleVertex[4] =
	{
		//頂点、頂点色
		{-0.5f,-0.5f},
		{0.5f,-0.5f },
		{0.5f,0.5f  },
		{-0.5f,0.5f }
	};



	//vao
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	//vbo
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	//頂点
	glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(Vertex), rectangleVertex, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT,GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	shader->setBindAttribVertex("position");



	/*
	//頂点カラー
	glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(Vertex), rectangleVertex, GL_STATIC_DRAW);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*) (4 * sizeof(float)));
	glEnableVertexAttribArray(1);
	*/





	//スケール
	glm::mat3 Scale = glm::mat3();
	Scale = glm::scale(Scale, glm::vec2(1, 1));

	//回転
	glm::mat3 Rotate = glm::mat3();
	Rotate = glm::rotate(Rotate, 1.0f);

	//平行移動
	glm::mat3 Translate = glm::mat3();
	Translate = glm::translate(Translate, glm::vec2(1, 1));

	glm::mat3 simpleView = glm::mat3();
	
	simpleView;






	
}

//更新
void DrawTest::Update()
{
	




}

//描画
void DrawTest::Draw()
{
	shader->setEnable();


	shader->setUniform4f("ufragment", glm::vec4(0.0, 1.0, 0.0, 1.0));



	glDrawArrays(GL_LINE_LOOP, 0, 4);

	shader->setDisable();
}

//デストラクタ
DrawTest::~DrawTest()
{
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);

}

