#ifndef ___ACTOR_HPP_
#define ___ACTOR_HPP_

#include <iostream>
#include "glm/glm.hpp"
class Window;

/*#########################################################################
# Actor全ての基底クラス
###########################################################################*/

class Actor
{
public:

	Actor(std::shared_ptr<Window> w);	//コンストラクタ
	~Actor();							//デストラクタ

	virtual void Update() = 0;						//更新
	virtual void Draw(glm::mat4 projection) = 0;	//描画

protected:

	std::shared_ptr<Window> windowContext;	//ウインドウコンテキスト

};


#endif