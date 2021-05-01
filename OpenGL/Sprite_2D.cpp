#include "Sprite_2D.hpp"

#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Shader.hpp"


//コンストラクタ
Sprite_2D::Sprite_2D(std::shared_ptr<Window> w) : Transform(w) 
{
	shader = std::make_shared<Shader>("Shader/BasicMono_2D.vert", "Shader/BasicMono_2D.frag");	//シェーダー

	
	//頂点情報
	Vertex rectangleVertex[6] =
	{
		//頂点、頂点色
		{-0.5f,0.5f},
		{-0.5f,-0.5f},
		{0.5f,0.5f},

		{0.5f,0.5f},
		{-0.5f,-0.5f},
		{0.5f,-0.5f},


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
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(Vertex), rectangleVertex, GL_STATIC_DRAW);
	glVertexAttribPointer(attrib, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (GLvoid*)0);
	shader->setBindAttribVertex("vertexPosition");


	
}

//更新
void Sprite_2D::Update()
{

}

//描画
void Sprite_2D::Draw(glm::mat4 projection)
{
	shader->setEnable();
	glBindVertexArray(vao);


	shader->setUniform4f("uFragment", glm::vec4(0.0, 0.0, 1.0, 1.0));
	shader->setUniformMatrix4fv("uTranslate", translate);
	shader->setUniformMatrix4fv("uRotate", rotate);
	shader->setUniformMatrix4fv("uScale", scale);
	shader->setUniformMatrix4fv("uViewProjection",projection);
	





	glDrawArrays(GL_TRIANGLES, 0, 6);

	shader->setDisable();
	glBindVertexArray(0);

}

//デストラクタ
Sprite_2D::~Sprite_2D()
{
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
}

