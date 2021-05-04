#ifndef ___Sprite_2D_HPP
#define ___Sprite_2D_HPP


#include <iostream>
#include <glew/include/GL/glew.h>
#include <glm/glm.hpp>

#include "Texture.hpp"
#include "Transform_2D.hpp"
#include "Shader.hpp"



class Sprite_2D : protected Transform_2D, public Shader
{
public:

	Sprite_2D(const char* vert = "Shader/BasicTexture_2D.vert", const char* frag = "Shader/BasicTexture_2D.frag");		//コンストラクタ
	~Sprite_2D();										//デストラクタ

	// ###################### メンバ関数 ###################### 
	
	void DrawGraph(glm::vec2 pos,glm::mat4 projection);							//描画
	void DrawRotateGraph(glm::vec2 pos, float angle, glm::mat4 projection);		//回転描画
	void DrawExtendGraph(glm::vec2 pos,glm::vec2 scale,glm::mat4 projection);	//スケール描画

	void setTexture(TextureData tex);			//テクスチャ設定
	void setDrawTextureID(unsigned char id);	//描画するテクスチャ番号を指定

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


	
};

#endif
