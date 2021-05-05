#ifndef ___Sprite_2D_HPP
#define ___Sprite_2D_HPP


#include <iostream>
#include <glew/include/GL/glew.h>
#include <glm/glm.hpp>

#include "Texture.hpp"
#include "Transform_2D.hpp"
#include "Shader.hpp"


class Window;
class Sprite_2D : protected Transform_2D, public Shader
{
public:

	Sprite_2D(std::shared_ptr<Window> w,const char* vert = "Shader/BasicTexture_2D.vert", const char* frag = "Shader/BasicTexture_2D.frag");		//コンストラクタ
	~Sprite_2D();										//デストラクタ

	// ###################### メンバ関数 ###################### 
	
	void DrawGraph(glm::vec2 pos,unsigned char texNum);							//描画
	void DrawRotateGraph(glm::vec2 pos, float angle,unsigned char texNum);		//回転描画
	void DrawExtendGraph(glm::vec2 pos,glm::vec2 scale,unsigned char texNum);	//スケール描画

	void setTexture(TextureData tex);			//テクスチャ設定

private:

	//頂点配列
	struct Vertex
	{
		GLfloat position[2];	//座標
		GLfloat uv[2];			//UV
	};


	void setDrawTextureID(unsigned char id);	//描画するテクスチャ番号を指定




	std::vector<TextureData> textureID;	//テクスチャーID
	unsigned char textureNumber;	//テクスチャーIDを選択
	unsigned char textureUnitCount;	//テクスチャー番号をカウント
	GLuint vao;							//VertexArrayObject
	GLuint vbo;							//VertexBufferObject	

	std::shared_ptr<Window> windowContext;
};

#endif
