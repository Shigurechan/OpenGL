#include "Transform_2D.hpp"
#include "Actor.hpp"

// ###################### コンストラクタ ###################### 
Transform_2D::Transform_2D(std::shared_ptr<Window> w) : Actor(w)
{
	//パラメータを初期化
	vecScale = glm::vec3(0.0f, 0.0f, 0.0f);			//拡大縮小
	vecSize = glm::vec3(0.0,0.0,0.0);				//画像サイズ
	
	angle = 0.0f;									//回転量
	vecTranslate = glm::vec3(0.0f,0.0f, 0.0f);	//平行移動

	//行列を初期化
	scale = glm::scale(glm::mat4(1), vecScale);
	rotate = glm::rotate(angle, glm::vec3(0.0, 0.0, 1.0));
	translate = glm::translate(glm::mat4(1), vecTranslate);
}



// ###################### Transform_2D　設定 ###################### 

//スケール
void Transform_2D::setScale(glm::vec3 s)
{
	vecScale = s;
	scale = glm::scale(glm::mat4(1), vecScale + vecSize);
}

//回転
void Transform_2D::setRotate(float a)
{
	
	angle = a;

	glm::mat4 m = glm::translate(translate, glm::vec3(vecSize.x * 0.5f, vecSize.y * 0.5f, 0));		//平行移動
	rotate = glm::rotate(m, angle, glm::vec3(0.0,0.0,1.0));											//回転	
	m = glm::translate(translate, glm::vec3(-vecSize.x * 0.5f, -vecSize.y * 0.5f, 0));				//平行移動
	rotate = glm::rotate(m, angle, glm::vec3(0.0, 0.0, 1.0));										//回転
}

//平行移動
void Transform_2D::setTranslate(glm::vec3 t)
{	
	vecTranslate = t;
	translate = glm::translate(glm::mat4(1), vecTranslate);
}

//画像サイズを設定
void Transform_2D::setSizeScale(glm::vec2 s)
{
	vecSize = glm::vec3(s.x,s.y,0.0);
	scale = glm::scale(glm::mat4(1), vecSize);

}





// ###################### Transform_2D　取得 ###################### 

//スケール
glm::vec3 Transform_2D::getScale()
{
	return vecScale;
}

//回転量
float Transform_2D::getRotateAngle()
{
	return angle;

}

//平行移動
glm::vec3 Transform_2D::getTranslate()
{
	return vecTranslate;
}


// ###################### デストラクタ ###################### 
Transform_2D::~Transform_2D()
{

}
