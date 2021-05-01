#ifndef ___Sprite_2D_HPP
#define ___Sprite_2D_HPP


#include <iostream>
#include <glew/include/GL/glew.h>
#include <glm/glm.hpp>

#include "Transform_2D.hpp"
#include "Shader.hpp"


class Window;




class Sprite_2D : public Transform_2D,public Shader
{
public:

	//頂点配列
	struct Vertex
	{
		GLfloat position[2];	//座標
		GLfloat uv[2];			//UV
	};



	Sprite_2D(std::shared_ptr<Window> w, const char* vert, const char* frag);		//コンストラクタ
	~Sprite_2D();																	//デストラクタ

	virtual void Update();						//更新
	virtual void Draw(glm::mat4 projection);	//描画

private:

	



	GLuint vao;	//VertexArrayObject
	GLuint vbo;	//VertexBufferObject


};

#endif
