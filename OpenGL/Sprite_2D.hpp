#ifndef ___Sprite_2D_HPP
#define ___Sprite_2D_HPP


#include <iostream>
#include <glew/include/GL/glew.h>
#include <glm/glm.hpp>

#include "Transform.hpp"

class Shader;
class Window;

class Sprite_2D : public Transform
{
public:

	//頂点配列
	struct Vertex
	{
		GLfloat position[2];
	};



	Sprite_2D(std::shared_ptr<Window> w);		//コンストラクタ
	~Sprite_2D();								//デストラクタ

	virtual void Update();						//更新
	virtual void Draw(glm::mat4 projection);	//描画

private:

	std::shared_ptr<Shader> shader;	//シェーダークラス



	GLuint vao;	//VertexArrayObject
	GLuint vbo;	//VertexBufferObject


};

#endif
