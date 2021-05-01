#include "Actor.hpp"


class Window;
//コンストラクタ
Actor::Actor(std::shared_ptr<Window> w)
{
	windowContext = w;
}

//デストラクタ
Actor::~Actor()
{

}
