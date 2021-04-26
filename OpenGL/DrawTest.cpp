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
	Vertex rectangleVertex[6] =
	{
		//���_�A���_�F
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

	//���_	
	GLint attrib = shader->getAttribLocation("vertexPosition");
	glEnableVertexAttribArray(attrib);
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(Vertex), rectangleVertex, GL_STATIC_DRAW);
	glVertexAttribPointer(attrib, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (GLvoid*)0);
	shader->setBindAttribVertex("vertexPosition");


	//���f���s��
	vecScale = glm::vec3(1.0f, 1.0f, 1.0f);			//�g��k��
	vecRotate = glm::vec3(1.0f, 1.0f, 1.0f);		//��]
	angle = 0.0f;									//��]��
	vecTranslate = glm::vec3(0.0f, 0.0f, 0.0f);		//���s�ړ�
	translate = glm::translate(glm::mat4(1), vecTranslate);	//���s�ړ�
	rotate = glm::rotate(angle, vecRotate);					//��]
	scale = glm::scale(glm::mat4(1), vecScale);				//�g��k��

	//�r���[
	glm::vec3 pos = glm::vec3(0, 0, 1);			//���W
	glm::vec3 center = glm::vec3(0, 0, -1);		//����
	glm::vec3 up = glm::vec3(0, 1, 0);			//�����
	view = glm::lookAt(pos, center, up);


	projection = glm::perspective(glm::radians(90.0f), 4.0f / 3.0f, 0.1f, 100.0f);//�����ˌ`

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


	
	


	glDrawArrays(GL_TRIANGLES, 0, 6);

	shader->setDisable();
}

//�f�X�g���N�^
DrawTest::~DrawTest()
{
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);	
}

