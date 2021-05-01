#include "Transform.hpp"
#include "Actor.hpp"

// ###################### コンストラクタ ###################### 
Transform::Transform(std::shared_ptr<Window> w) : Actor(w)
{
	//パラメータを初期化
	vecScale = glm::vec3(1.0f, 1.0f, 1.0f);			//拡大縮小
	vecRotate = glm::vec3(1.0f, 1.0f, 1.0f);		//回転
	angle = 0.0f;									//回転量
	vecTranslate = glm::vec3(0.0f, 0.0f, 0.0f);		//平行移動

	//行列を初期化
	scale = glm::scale(glm::mat4(1), vecScale);
	rotate = glm::rotate(angle, vecRotate);
	translate = glm::translate(glm::mat4(1), vecTranslate);

}



// ###################### Transform　設定 ###################### 

//スケール
void Transform::setScale(glm::vec3 s)
{
	vecScale = s;
	scale = glm::scale(glm::mat4(1), vecScale);
}

//回転
void Transform::setRotate(glm::vec3 r, float a)
{
	vecRotate = r;
	angle = a;
	rotate = glm::rotate(angle, vecRotate);
}

//平行移動
void Transform::setTransform(glm::vec3 t)
{	
	vecTranslate = t;
	translate = glm::translate(glm::mat4(1), vecTranslate);
}

// ###################### Transform　取得 ###################### 

//スケール
glm::vec3 Transform::getScale()
{
	return vecScale;
}

//回転
glm::vec3 Transform::getRotate()
{
	return vecRotate;

}

//回転量
float Transform::getRotateAngle()
{
	return angle;

}

//平行移動
glm::vec3 Transform::getTransform()
{
	return vecTranslate;
}


// ###################### デストラクタ ###################### 
Transform::~Transform()
{

}
