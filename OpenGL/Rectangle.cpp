#include "Rectangle.hpp"
#include "Window.hpp"
#include "Shader.hpp"


// ###################### コンストラクタ ###################### 
Rectangle::Rectangle(std::shared_ptr<Window> w, const char* vert, const char* frag) : Transform_2D(), Shader()
{
	
	windowContext = w;	//ウインドウコンテキスト


	//シェーダー読み込み
	if (vert == NULL && frag == NULL)
	{
		vert = "Shader/2D/BasicMono_VertColor_2D.vert";
		frag = "Shader/2D/BasicMono_VertColor_2D.frag";
		isDefaultShader = true;
	}
	else {
		isDefaultShader = false;

	}

	LoadShader(vert,frag);	//シェーダーファイルを読み込み

	//頂点情報
	
	//vao
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	//vbo
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	//頂点	
	GLint attrib = getAttribLocation("vertexPosition");
	glEnableVertexAttribArray(attrib);
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(VertexColor), rectangleVertex, GL_STATIC_DRAW);
	glVertexAttribPointer(attrib, 2, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	setBindAttribVertex("vertexPosition");

	//頂点カラー
	attrib = getAttribLocation("vertexColor");
	glEnableVertexAttribArray(attrib);
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(VertexColor), rectangleVertex, GL_STATIC_DRAW);
	glVertexAttribPointer(attrib, 4, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(sizeof(GLfloat) * 2));
	setBindAttribFragment("vertexColor");


	//アルファブレンド有効
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

// ###################### メンバ関数 ###################### 

//頂点カラーを設定
void Rectangle::setVertexALLColor(glm::vec4 color)
{
	

	float c = 1.0f / 255.0f;

	rectangleVertex[0].color[0] =  c * color.x;
	rectangleVertex[0].color[1] = c * color.y;
	rectangleVertex[0].color[2] = c * color.z;
	rectangleVertex[0].color[3] = c * color.w;

	rectangleVertex[1].color[0] = c * color.x;
	rectangleVertex[1].color[1] = c * color.y;
	rectangleVertex[1].color[2] = c * color.z;
	rectangleVertex[1].color[3] = c * color.w;

	rectangleVertex[2].color[0] = c * color.x;
	rectangleVertex[2].color[1] = c * color.y;
	rectangleVertex[2].color[2] = c * color.z;
	rectangleVertex[2].color[3] = c * color.w;

	rectangleVertex[3].color[0] = c * color.x;
	rectangleVertex[3].color[1] = c * color.y;
	rectangleVertex[3].color[2] = c * color.z;
	rectangleVertex[3].color[3] = c * color.w;

	rectangleVertex[4].color[0] = c * color.x;
	rectangleVertex[4].color[1] = c * color.y;
	rectangleVertex[4].color[2] = c * color.z;
	rectangleVertex[4].color[3] = c * color.w;

	rectangleVertex[5].color[0] = c * color.x;
	rectangleVertex[5].color[1] = c * color.y;
	rectangleVertex[5].color[2] = c * color.z;
	rectangleVertex[5].color[3] = c * color.w;


}


//頂点カラーを設定
void Rectangle::setVertexColor(int vertNum,glm::vec4 color)
{
	float c = 1.0f / 255.0f;

	
	rectangleVertex[vertNum].color[0] = c * color.x;
	rectangleVertex[vertNum].color[1] = c * color.y;
	rectangleVertex[vertNum].color[2] = c * color.z;
	rectangleVertex[vertNum].color[3] = c * color.w;

}





//描画
void Rectangle::Draw(glm::vec2 start,glm::vec2 end,glm::vec4 color)
{
	if (isDefaultShader == true) {
		setEnable();
	}

	setVertexALLColor(color);	//頂点カラーを再設定

	glBindVertexArray(vao);

	//頂点カラー
	GLint attrib = getAttribLocation("vertexColor");
	glEnableVertexAttribArray(attrib);
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(VertexColor), rectangleVertex, GL_STATIC_DRAW);
	glVertexAttribPointer(attrib, 4, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(sizeof(GLfloat) * 2));
	setBindAttribFragment("vertexColor");

	//Transform
	setSizeScale(glm::vec2((end.x - start.x) / 2.0f, (end.x - start.x) / 2.0f));			//サイズ	
	setScale(glm::vec2(getSizeScale().x, getSizeScale().y));								//スケール
	setTranslate(glm::vec3(start.x + getSizeScale().x, start.y + getSizeScale().y, 0.0f));	//平行移動

	//Uniform
	setUniformMatrix4fv("uTranslate", translate);
	setUniformMatrix4fv("uRotate", rotate);
	setUniformMatrix4fv("uScale", scale);
	setUniformMatrix4fv("uViewProjection", glm::ortho(0.0f, windowContext->getSize().x, windowContext->getSize().y, 0.0f, -1.0f, 1.0f));
	
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);	


	if (isDefaultShader == true) {
		setDisable();
	}
}



//回転描画
void Rectangle::DrawRotate(glm::vec2 start, glm::vec2 end,float angle, glm::vec4 color)
{
	if (isDefaultShader == true) {
		setEnable();
	}

	setVertexALLColor(color);	//頂点カラーを再設定

	glBindVertexArray(vao);

	//頂点カラー
	GLint attrib = getAttribLocation("vertexColor");
	glEnableVertexAttribArray(attrib);
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(VertexColor), rectangleVertex, GL_STATIC_DRAW);
	glVertexAttribPointer(attrib, 4, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(sizeof(GLfloat) * 2));
	setBindAttribFragment("vertexColor");

	//Transform
	setSizeScale(glm::vec2((end.x - start.x), (end.y - start.y)));							//サイズ	
	setRotate(angle);																		//回転
	setScale(glm::vec2(getSizeScale().x, getSizeScale().y));								//スケール
	setTranslate(glm::vec3((start.x + getSizeScale().x) / 2.0f, (start.y + getSizeScale().y) / 2.0f, 0.0f));	//平行移動


	//Uniform
	setUniformMatrix4fv("uTranslate", translate);
	setUniformMatrix4fv("uRotate", rotate);
	setUniformMatrix4fv("uScale", scale);
	setUniformMatrix4fv("uViewProjection", glm::ortho(0.0f, windowContext->getSize().x, windowContext->getSize().y, 0.0f, -1.0f, 1.0f));

	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);


	if (isDefaultShader == true) {
		setDisable();
	}
}




//描画
void Rectangle::DrawColor(glm::vec2 start, glm::vec2 end, glm::vec4 lu, glm::vec4 ru, glm::vec4 rd, glm::vec4 ld)
{
	if (isDefaultShader == true) {
		setEnable();
	}

	//頂点カラーを設定
	setVertexColor(0, ld);
	setVertexColor(1, lu);
	setVertexColor(2, rd);
	setVertexColor(3, rd);
	setVertexColor(4, lu);
	setVertexColor(5, ru);
	

	glBindVertexArray(vao);

	//頂点カラー
	GLint attrib = getAttribLocation("vertexColor");
	glEnableVertexAttribArray(attrib);
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(VertexColor), rectangleVertex, GL_STATIC_DRAW);
	glVertexAttribPointer(attrib, 4, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(sizeof(GLfloat) * 2));
	setBindAttribFragment("vertexColor");

	//Transform
	setSizeScale(glm::vec2((end.x - start.x) / 2.0f, (end.x - start.x) / 2.0f));			//サイズ	
	setScale(glm::vec2(getSizeScale().x, getSizeScale().y));								//スケール
	setTranslate(glm::vec3(start.x + getSizeScale().x, start.y + getSizeScale().y, 0.0f));	//平行移動

	//Uniform
	setUniformMatrix4fv("uTranslate", translate);
	setUniformMatrix4fv("uRotate", rotate);
	setUniformMatrix4fv("uScale", scale);
	setUniformMatrix4fv("uViewProjection", glm::ortho(0.0f, windowContext->getSize().x, windowContext->getSize().y, 0.0f, -1.0f, 1.0f));



	glDrawArrays(GL_TRIANGLES, 0, 6);


	glBindVertexArray(0);


	if (isDefaultShader == true) {
		setDisable();
	}
}













// ###################### デストラクタ ###################### 
Rectangle::~Rectangle()
{

}


