#ifndef ___TRANSFORM_HPP_
#define ___TRANSFORM_HPP_

#include <iostream>
#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>

#include "Actor.hpp"


class Window;
/*#########################################################################
# トランスフォームクラス: Actorクラスを継承

説明
	全ての描画物はこれを継承する
###########################################################################*/

class Transform : public Actor
{
public:

	Transform(std::shared_ptr<Window> w);	//コンストラクタ
	~Transform();							//デストラクタ



	// ###################### Transform　設定 ###################### 
	void setScale(glm::vec3 s);				//スケール
	void setRotate(glm::vec3 r,float a);	//回転
	void setTransform(glm::vec3 t);			//平行移動

	// ###################### Transform　取得 ###################### 
	glm::vec3 getScale();		//スケール
	glm::vec3 getRotate();		//回転
	float getRotateAngle();		//回転量
	glm::vec3 getTransform();	//平行移動


protected:

	//パラメータ
	glm::vec3 vecScale;		//拡大縮小
	glm::vec3 vecRotate;	//回転
	float angle;			//回転量
	glm::vec3 vecTranslate;	//平行移動


	//描画行列
	glm::mat4 scale;		//拡大縮小
	glm::mat4 rotate;		//回転
	glm::mat4 translate;	//平行移動
	


};


#endif
