#include "DrawTest.hpp"

#include <iostream>
#include "Shader.hpp"
#include <glm/gtx/matrix_transform_2d.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

//�R���X�g���N�^
DrawTest::DrawTest()
{
	shader = std::make_shared<Shader>("Basic_2D.vert","Basic_2D.frag");	//�V�F�[�_�[

	//���_�z��
	struct Vertex
	{
		GLfloat position[2];
	//	GLfloat color[4];
	};

	//���_���
	Vertex rectangleVertex[4] =
	{
		//���_�A���_�F
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

	//���_
	glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(Vertex), rectangleVertex, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT,GL_FALSE, 2 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);



	/*
	//���_�J���[
	glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(Vertex), rectangleVertex, GL_STATIC_DRAW);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*) (4 * sizeof(float)));
	glEnableVertexAttribArray(1);
	*/





	//�X�P�[��
	scale = glm::scale(scale, glm::vec2(1, 1));

	//��]	
	rotate = glm::rotate(rotate, 1.0f);

	//���s�ړ�	
	translate = glm::translate(translate, glm::vec2(1, 1));

	
	sv[0] = 2.0f / 640.0f;
	sv[1] = 0.0f;
	sv[2] = 0.0f;

	sv[3] = 0.0f;
	sv[4] = 2.0f / 480.0f;
	sv[5] = 0.0f;

	sv[6] = 0.0f;
	sv[7] = 0.0f;
	sv[8] = 1.0f;


//	simpleView = glm::value_ptr(sv);




	
}

//�X�V
void DrawTest::Update()
{
	




}

//�`��
void DrawTest::Draw()
{
	shader->setEnable();


	shader->setUniform4f("uFragment", glm::vec4(0.0, 0.0, 1.0, 1.0));
	shader->setUniformMatrix3fv("uScale", scale);
	shader->setUniformMatrix3fv("uRotate", rotate);
	shader->setUniformMatrix3fv("uTranslate", translate);
//	shader->setUniformMatrix3fv("uSimpleView", simpleView);

	shader->setUniformMatrix3fv_test("uSimpleView", sv);
	shader->setBindAttribVertex("position");




	glDrawArrays(GL_LINE_LOOP, 0, 4);

	shader->setDisable();
}

//�f�X�g���N�^
DrawTest::~DrawTest()
{
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);	
}

