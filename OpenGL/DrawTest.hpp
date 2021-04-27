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

	
	//パラメータ
	glm::vec3 vecScale;		//拡大縮小
	glm::vec3 vecRotate;	//回転
	float angle;			//回転量
	glm::vec3 vecTranslate;	//平行移動


	//描画行列
	glm::mat4 scale;		//拡大縮小
	glm::mat4 rotate;		//回転
	glm::mat4 translate;	//平行移動
	glm::mat4 view;			//ビュー
	glm::mat4 projection;	//射形
};

#endif
