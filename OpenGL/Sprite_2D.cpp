#include "Sprite_2D.hpp"

#include <iostream>
#include <fstream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_Transform.hpp>
#include <glm/gtx/Transform.hpp>


#include "Shader.hpp"

//"Shader/BasicTexture_2D.vert", "Shader/BasicTexture_2D.frag"
//コンストラクタ
Sprite_2D::Sprite_2D(const char* vert,const char* frag) : Transform_2D(),Shader()
{
	//シェーダー読み込み
	LoadShader(vert, frag);	
	textureNumber = 0;
	textureID = std::vector<TextureData>();
	textureUnitCount = 0;

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


	//アルファブレンド有効
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}


// ###################### メンバ関数 ###################### 

//テクスチャ設定
void Sprite_2D::setTexture(TextureData tex)
{
	
	textureID.push_back(tex);	//テクスチャーIDに追加

	
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


	textureID.back().textureNumber = GL_TEXTURE0 + textureUnitCount;
	assert(textureID.size() < GL_TEXTURE31);

	textureUnitCount++;	//テクスチャーユニットカウントに加算
}

//描画するテクスチャ番号を指定
void Sprite_2D::setDrawTextureID(unsigned char id)
{
	assert(id < textureID.size());
	glActiveTexture(textureID.at(id).textureNumber);
	textureNumber = textureID.at(id).textureNumber;
}

//描画
void Sprite_2D::DrawGraph(glm::vec2 pos,glm::mat4 projection,unsigned char texNum)
{	


	setDrawTextureID((unsigned char)texNum);	//テクチャーユニットを設定
	glBindVertexArray(vao);
	glBindTexture(GL_TEXTURE_2D, textureID.at(texNum).ID);
	


	setTranslate(glm::vec3(pos.x + (textureID.at(texNum).size.x / 2.0f), pos.y + (textureID.at(texNum).size.y / 2.0f), 0.0f));	//平行移動

	//uniform
	setUniformMatrix4fv("uTranslate", translate);
	setUniformMatrix4fv("uRotate", rotate);
	setUniformMatrix4fv("uScale", scale);
	setUniformMatrix4fv("uViewProjection",projection);
	
	glDrawArrays(GL_TRIANGLES, 0, 6);

	
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);
}

//回転描画
void Sprite_2D::DrawRotateGraph(glm::vec2 pos, float angle, glm::mat4 projection,unsigned char texNum)
{

	glBindVertexArray(vao);
	glBindTexture(GL_TEXTURE_2D, textureID.at(texNum).ID);

	setRotate(angle);	//回転
	setTranslate(glm::vec3(pos.x + (textureID.at(texNum).size.x / 2.0f), pos.y + (textureID.at(texNum).size.y / 2.0f), 0.0f));	//平行移動

	//uniform
	setUniformMatrix4fv("uTranslate", translate);
	setUniformMatrix4fv("uRotate", rotate);
	setUniformMatrix4fv("uScale", scale);
	setUniformMatrix4fv("uViewProjection", projection);

	glDrawArrays(GL_TRIANGLES, 0, 6);

	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);

}

//スケール描画
void Sprite_2D::DrawExtendGraph(glm::vec2 pos, glm::vec2 s, glm::mat4 projection,unsigned char texNum)
{

	glBindVertexArray(vao);
	glBindTexture(GL_TEXTURE_2D, textureID.at(texNum).ID);

	setScale(s);	//スケール
	setTranslate(glm::vec3(pos.x + (textureID.at(texNum).size.x / 2.0f), pos.y + (textureID.at(texNum).size.y / 2.0f), 0.0f));	//平行移動

	//Uniform
	setUniformMatrix4fv("uTranslate", translate);
	setUniformMatrix4fv("uRotate", rotate);
	setUniformMatrix4fv("uScale", scale);
	setUniformMatrix4fv("uViewProjection", projection);


	glDrawArrays(GL_TRIANGLES, 0, 6);

	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);
}



//デストラクタ
Sprite_2D::~Sprite_2D()
{
	//テクスチャーIDを開放
	for (int i = 0; i < textureID.size(); i++)
	{
		glDeleteTextures(1,&textureID.at(i).ID);
		delete[] textureID.at(i).fileData;
		textureID.at(i).fileData = NULL;
	}

	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
}

