#include "Actor.hpp"


class Window;
//�R���X�g���N�^
Actor::Actor(std::shared_ptr<Window> w)
{
	windowContext = w;
}

//�f�X�g���N�^
Actor::~Actor()
{

}
