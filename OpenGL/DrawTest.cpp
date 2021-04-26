#include "DrawTest.hpp"

#include <iostream>
#include "Shader.hpp"

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>
//�R���X�g���N�^
DrawTest::DrawTest()
{
	shader = std::make_shared<Shader>("Basic_2D.vert", "Basic_2D.frag");	//�V�F�[�_�[

	//���_�z��
	struct Vertex
	{
		GLfloat position[2];
	};

	//���_���
	Vertex rectangleVertex[4] =
	{
		//���_�A���_�F
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



	//���_	
	GLint attrib = shader->getAttribLocation("vertexPosition");
	glEnableVertexAttribArray(attrib);
	glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(Vertex), rectangleVertex, GL_STATIC_DRAW);
	glVertexAttribPointer(attrib, 2, GL_FLOAT,GL_FALSE, 2 * sizeof(GLfloat), (GLvoid*)0);
	shader->setBindAttribVertex("vertexPosition");


	//���f���s��
	translate = glm::translate(glm::mat4(), glm::vec3(0.0f, 0.0f, -5.0f));	//���s�ړ�
	rotate = glm::rotate(0.0f, glm::vec3(0.0f, 0.0f, 0.0f));				//��]
	scale = glm::scale(glm::mat4(), glm::vec3(1.0f, 1.0f, 1.0f));			//�g��k��

	//�r���[
	glm::vec3 pos = glm::vec3(0, 0, 50);
	glm::vec3 center = glm::vec3(0, 0, -1);
	glm::vec3 up = glm::vec3(0,1,0);

	view = glm::lookAt(pos,center,up);	

	//�����ˌ`
	projection = glm::perspective(glm::radians(90.0f),4.0f / 3.0f ,0.1f,100.0f);

	



	
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
	shader->setUniformMatrix4fv("uTranslate", translate);
	shader->setUniformMatrix4fv("uRotate", rotate);
	shader->setUniformMatrix4fv("uScale", scale);

	shader->setUniformMatrix4fv("uProjection", projection);
	shader->setUniformMatrix4fv("uView", view);


	
	


	glDrawArrays(GL_LINE_LOOP, 0, 4);

	shader->setDisable();
}

//�f�X�g���N�^
DrawTest::~DrawTest()
{
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);	
}

