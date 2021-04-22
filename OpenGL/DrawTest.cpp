#include "DrawTest.hpp"

//�R���X�g���N�^
DrawTest::DrawTest()
{

	struct Vertex
	{
		GLfloat position[2];
//		GLfloat color[4];
	};



	//���_���W
	Vertex rectangleVertex[4] =
	{
		//���_�A���_�F
		{-0.5f,-0.5f},
		{0.5f,-0.5f },
		{0.5f,0.5f  },
		{-0.5f,0.5f }
	};


/*
	//���_���W
	Vertex rectangleVertex[4] =
	{
		//���_�A���_�F
		{-0.5f,-0.5f,   0.0,0.0,1.0,1.0},
		{0.5f,-0.5f ,   0.0,0.0,1.0,1.0},
		{0.5f,0.5f  ,   0.0,0.0,1.0,1.0},
		{-0.5f,0.5f ,   0.0,0.0,1.0,1.0}
	};

	*/

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
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*) (2 * sizeof(float)));
	glEnableVertexAttribArray(1);
	*/
}

//�X�V
void DrawTest::Update()
{

}

//�`��
void DrawTest::Draw()
{
	glBindVertexArray(vao);
	glDrawArrays(GL_LINE_LOOP, 0, 4);
}

//�f�X�g���N�^
DrawTest::~DrawTest()
{
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);

}
