#include "DrawTest.hpp"

#include <iostream>
#include "Shader.hpp"

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>
//コンストラクタ
DrawTest::DrawTest()
{
	shader = std::make_shared<Shader>("Basic_2D.vert", "Basic_2D.frag");	//シェーダー

	//頂点配列
	struct Vertex
	{
		GLfloat position[2];
	};

	//頂点情報
	Vertex rectangleVertex[4] =
	{
		//頂点、頂点色
		{-0.5f,-0.5f},
		{0.5f,-0.5f},
		{0.5f,0.5f},
		{-0.5f,0.5f}
	};

	//vao
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	//vbo
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);



	//頂点	
	GLint attrib = shader->getAttribLocation("vertexPosition");
	glEnableVertexAttribArray(attrib);
	glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(Vertex), rectangleVertex, GL_STATIC_DRAW);
	glVertexAttribPointer(attrib, 2, GL_FLOAT,GL_FALSE, 2 * sizeof(GLfloat), (GLvoid*)0);
	shader->setBindAttribVertex("vertexPosition");


	//モデル行列
	translate = glm::translate(glm::mat4(), glm::vec3(0.0f, 0.0f, -5.0f));	//平行移動
	rotate = glm::rotate(0.0f, glm::vec3(0.0f, 0.0f, 0.0f));				//回転
	scale = glm::scale(glm::mat4(), glm::vec3(1.0f, 1.0f, 1.0f));			//拡大縮小

	//ビュー
	glm::vec3 pos = glm::vec3(0, 0, 50);
	glm::vec3 center = glm::vec3(0, 0, -1);
	glm::vec3 up = glm::vec3(0,1,0);

	view = glm::lookAt(pos,center,up);	

	//透視射形
	projection = glm::perspective(glm::radians(90.0f),4.0f / 3.0f ,0.1f,100.0f);

	



	
}

//更新
void DrawTest::Update()
{
	




}

//描画
void DrawTest::Draw()
{
	shader->setEnable();

	
	shader->setUniform4f("uFragment", glm::vec4(0.0, 0.0, 1.0, 1.0));
	shader->setUniformMatrix4fv("uTranslate", translate);
	shader->setUniformMatrix4fv("uRotate", rotate);
	shader->setUniformMatrix4fv("uScale", scale);

	shader->setUniformMatrix4fv("uProjection", projection);
	shader->setUniformMatrix4fv("uView", view);


	
	


	glDrawArrays(GL_LINE_LOOP, 0, 4);

	shader->setDisable();
}

//デストラクタ
DrawTest::~DrawTest()
{
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);	
}

