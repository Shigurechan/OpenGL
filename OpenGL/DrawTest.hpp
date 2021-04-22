#ifndef ___DRAWTEST_HPP
#define ___DRAWTEST_HPP

#include <iostream>
#include <glew/include/GL/glew.h>

class DrawTest
{
public:
	DrawTest();		//コンストラクタ
	~DrawTest();	//デストラクタ

	void Update();	//更新
	void Draw();	//描画

private:
	

	GLuint vao;	//VertexArrayObject
	GLuint vbo;	//VertexBufferObject


};

#endif
