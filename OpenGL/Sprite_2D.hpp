#ifndef ___Sprite_2D_HPP
#define ___Sprite_2D_HPP


#include <iostream>
#include <glew/include/GL/glew.h>
#include <glm/glm.hpp>

#include "Texture.hpp"
#include "Transform_2D.hpp"
#include "Shader.hpp"


class Window;
class Sprite_2D : protected Transform_2D,public Shader
{
public:

	Sprite_2D(std::shared_ptr<Window> w, const char* vert, const char* frag);		//コンストラクタ
	~Sprite_2D();																	//デストラクタ

	virtual void Update();						//更新
	virtual void Draw(glm::mat4 projection);	//描画

	// ###################### メンバ関数 ###################### 
	void setTexture(TextureData tex);			//テクスチャ設定
	void setDrawTextureID(unsigned char id);	//描画するテクスチャ番号を指定

	void setPosition(const glm::vec2 p);		//移動
	void setRotation(const float a);			//回転
	void setScaling(const glm::vec2 s);			//スケール


private:

	//頂点配列
	struct Vertex
	{
		GLfloat position[2];	//座標
		GLfloat uv[2];			//UV
	};



	std::vector<TextureData> textureID;	//テクスチャーID
	int selectID;						//テクスチャーIDを選択
	GLuint vao;						//VertexArrayObject
	GLuint vbo;						//VertexBufferObject


	glm::vec2 Position;//
};

#endif
