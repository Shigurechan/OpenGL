#include "Sprite_2D.hpp"

#include <iostream>
#include <fstream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_Transform.hpp>
#include <glm/gtx/Transform.hpp>


#include "Shader.hpp"


//コンストラクタ
Sprite_2D::Sprite_2D(std::shared_ptr<Window> w,const char* vert,const char* frag) : Transform_2D(w),Shader()
{
	//シェーダー読み込み
	LoadShader(vert, frag);	
	selectID = -1;
	Position = glm::vec2(0,0);
	//頂点情報
	Vertex rectangleVertex[6] =
	{
		//頂点、頂点色
		{-0.5f,0.5f,     0.0f,1.0f},
		{-0.5f,-0.5f,	0.0f,0.0f},
		{0.5f,0.5f,		1.0f,1.0f},

		{0.5f,0.5f,		1.0f,1.0f},
		{-0.5f,-0.5f,    0.0f,0.0f},
		{0.5f,-0.5f,     1.0f,0.0f},


	};

	//vao
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	//vbo
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	//頂点	
	GLint attrib = getAttribLocation("vertexPosition");
	glEnableVertexAttribArray(attrib);
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(Vertex), rectangleVertex, GL_STATIC_DRAW);
	glVertexAttribPointer(attrib, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)0);
	setBindAttribVertex("vertexPosition");

	attrib = getAttribLocation("vertexUV");
	glEnableVertexAttribArray(attrib);
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(Vertex), rectangleVertex, GL_STATIC_DRAW);
	glVertexAttribPointer(attrib, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)(sizeof(GLfloat) * 2));
	setBindAttribVertex("vertexUV");

	/*
	// テクスチャIDの生成
	glGenTextures(1, &texID);

	// ファイルの読み込み
	int x = 0;
	int y = 0;
	int channel = 0;
	unsigned char* fileData = stbi_load("texture.png",&x,&y,&channel,0);
	


	glBindTexture(GL_TEXTURE_2D, texID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 800, 800, 0, GL_RGBA, GL_UNSIGNED_BYTE, fileData);
	
	// テクスチャの設定
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	*/


	
	








	//アルファブレンド有効
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//stbi_image_free(fileData);//画像データ開放



}


// ###################### メンバ関数 ###################### 

//テクスチャ設定
void Sprite_2D::setTexture(TextureData tex)
{
	
	textureID.push_back(tex);

	
	glGenTextures(1, &textureID.back().ID);	//テクスチャIDの生成

	//バインド
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glBindTexture(GL_TEXTURE_2D, textureID.back().ID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, textureID.back().size.x, textureID.back().size.y, 0, GL_RGBA, GL_UNSIGNED_BYTE, textureID.back().fileData);

	// テクスチャの補間設定
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	setSizeScale(glm::vec3(textureID.back().size.x, textureID.back().size.y, 1.0f));	//スプライトサイズを設定

	//自動で最後にロードしてテクスチャを描画するように設定
	glActiveTexture(textureID.back().ID);
	selectID++;

}

//描画するテクスチャ番号を指定
void Sprite_2D::setDrawTextureID(unsigned char id)
{
	assert(id > textureID.size());

	glActiveTexture(textureID.at(id).ID);
}

//移動
void Sprite_2D::setPosition(const glm::vec2 p)
{
	setTranslate(glm::vec3(p.x + (textureID.at(selectID).size.x / 2.0f),p.y + (textureID.at(selectID).size.y / 2.0f),0.0f));
}

//回転
void Sprite_2D::setRotation(const float a)
{
	setRotate(a);
}

//スケール
void Sprite_2D::setScaling(const glm::vec2 s)
{
	setScaling(glm::vec3(s.x,s.y,0.0f));
}



// ###################### 毎フレーム ###################### 

//更新
void Sprite_2D::Update()
{

}

//描画
void Sprite_2D::Draw(glm::mat4 projection)
{	
	glBindVertexArray(vao);
	glBindTexture(GL_TEXTURE_2D, textureID.at(selectID).ID);
	

	setUniformMatrix4fv("uTranslate", translate);
	setUniformMatrix4fv("uRotate", rotate);
	setUniformMatrix4fv("uScale", scale);
	setUniformMatrix4fv("uViewProjection",projection);
	
	glDrawArrays(GL_TRIANGLES, 0, 6);

	
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);

}

//デストラクタ
Sprite_2D::~Sprite_2D()
{
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
}

