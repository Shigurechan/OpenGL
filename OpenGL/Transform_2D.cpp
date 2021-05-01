#include "Transform_2D.hpp"
#include "Actor.hpp"

// ###################### コンストラクタ ###################### 
Transform_2D::Transform_2D(std::shared_ptr<Window> w) : Actor(w)
{
	//パラメータを初期化
	vecScale = glm::vec3(100.0f, 100.0f, 1.0f);			//拡大縮小
	vecRotate = glm::vec3(1.0f, 1.0f, 1.0f);		//回転
	angle = 0.0f;									//回転量
	vecTranslate = glm::vec3(0.0f, 0.0f, 0.0f);		//平行移動

	//行列を初期化
	scale = glm::scale(glm::mat4(1), vecScale);
	rotate = glm::rotate(angle, vecRotate);
	translate = glm::translate(glm::mat4(1), vecTranslate);

}



// ###################### Transform_2D　設定 ###################### 

//スケール
void Transform_2D::setScale(glm::vec3 s)
{
	vecScale = s;
	scale = glm::scale(glm::mat4(1), vecScale);
}

//回転
void Transform_2D::setRotate(glm::vec3 r, float a)
{
	vecRotate = r;
	angle = a;
	rotate = glm::rotate(angle, vecRotate);
}

//平行移動
void Transform_2D::setTransform_2D(glm::vec3 t)
{	
	vecTranslate = t;
	translate = glm::translate(glm::mat4(1), vecTranslate);
}

// ###################### Transform_2D　取得 ###################### 

//スケール
glm::vec3 Transform_2D::getScale()
{
	return vecScale;
}

//回転
glm::vec3 Transform_2D::getRotate()
{
	return vecRotate;
}

//回転量
float Transform_2D::getRotateAngle()
{
	return angle;

}

//平行移動
glm::vec3 Transform_2D::getTransform_2D()
{
	return vecTranslate;
}


// ###################### デストラクタ ###################### 
Transform_2D::~Transform_2D()
{

}
