#ifndef ___DRAWTEST_HPP
#define ___DRAWTEST_HPP


#include <iostream>
#include <glew/include/GL/glew.h>

#include <glm/gtx/matrix_transform_2d.hpp>
#include <glm/glm.hpp>


class Shader;
class DrawTest
{
public:
	DrawTest();		//コンストラクタ
	~DrawTest();	//デストラクタ

	void Update();	//更新
	void Draw();	//描画

private:
	
	std::shared_ptr<Shader> shader;	//シェーダークラス


	GLuint vao;	//VertexArrayObject
	GLuint vbo;	//VertexBufferObject

	//スケール
	glm::mat3 scale;

	//回転
	glm::mat3 rotate;

	//平行移動
	glm::mat3 translate;

	//射形行列
	float sv[9];
	glm::mat3 simpleView;


};

#endif
