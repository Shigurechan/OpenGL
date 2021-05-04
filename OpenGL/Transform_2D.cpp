#include "Transform_2D.hpp"
#include "Actor.hpp"

// ###################### コンストラクタ ###################### 
Transform_2D::Transform_2D()
{
	size = glm::vec2(0,0);

	//行列を初期化
	scale = glm::scale(glm::mat4(1), glm::vec3(1.0f,1.0f,1.0f));
	rotate = glm::rotate(0.0f,glm::vec3(0.0, 0.0, 1.0));
	translate = glm::translate(glm::mat4(1), glm::vec3(1.0f,1.0f,1.0f));
}

// ###################### Transform_2D　設定 ###################### 

//スケール
void Transform_2D::setScale(glm::vec2 s)
{
	scale = glm::scale(glm::mat4(1), glm::vec3(s.x,s.y,0.0f) + glm::vec3(size.x,size.y,0.0f));
}

//回転
void Transform_2D::setRotate(float a)
{
	glm::mat4 m = glm::translate(translate, glm::vec3(size.x * 0.5f, size.y * 0.5f, 0));		//平行移動
	rotate = glm::rotate(m, a, glm::vec3(0.0,0.0,1.0));											//回転	
	m = glm::translate(translate, glm::vec3(-size.x * 0.5f, -size.y * 0.5f, 0));				//平行移動
	rotate = glm::rotate(m, a, glm::vec3(0.0, 0.0, 1.0));										//回転
}

//平行移動
void Transform_2D::setTranslate(glm::vec3 t)
{	
	translate = glm::translate(glm::mat4(1), t);
}

//画像サイズを設定
void Transform_2D::setSizeScale(glm::vec2 s)
{
	size = s;
	scale = glm::scale(glm::mat4(1), glm::vec3(s.x, s.y, 0.0f));
}

// ###################### デストラクタ ###################### 
Transform_2D::~Transform_2D()
{

}
