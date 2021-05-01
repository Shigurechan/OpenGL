#ifndef ___Transform_2D_HPP_
#define ___Transform_2D_HPP_

#include <iostream>
#include "glm/glm.hpp"
#include <glm/gtc/matrix_Transform.hpp>
#include <glm/gtx/Transform.hpp>

#include "Actor.hpp"


class Window;
/*#########################################################################
# トランスフォームクラス: Actorクラスを継承

説明
	全ての描画物はこれを継承する
###########################################################################*/

class Transform_2D : public Actor
{
public:

	Transform_2D(std::shared_ptr<Window> w);	//コンストラクタ
	~Transform_2D();							//デストラクタ



	// ###################### Transform_2D　設定 ###################### 
	void setScale(glm::vec3 s);				//スケール
	void setRotate(glm::vec3 r,float a);	//回転
	void setTransform_2D(glm::vec3 t);			//平行移動

	// ###################### Transform_2D　取得 ###################### 
	glm::vec3 getScale();		//スケール
	glm::vec3 getRotate();		//回転
	float getRotateAngle();		//回転量
	glm::vec3 getTransform_2D();	//平行移動


protected:

	

	//描画行列
	glm::mat4 scale;		//拡大縮小
	glm::mat4 rotate;		//回転
	glm::mat4 translate;	//平行移動
	

private:
	//パラメータ
	glm::vec3 vecScale;		//拡大縮小
	glm::vec3 vecRotate;	//回転
	float angle;			//回転量
	glm::vec3 vecTranslate;	//平行移動


};


#endif
