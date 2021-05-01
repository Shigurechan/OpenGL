#ifndef ___ACTOR_HPP_
#define ___ACTOR_HPP_

#include <iostream>
#include "glm/glm.hpp"
class Window;

/*#########################################################################
# Actor�S�Ă̊��N���X
###########################################################################*/

class Actor
{
public:

	Actor(std::shared_ptr<Window> w);	//�R���X�g���N�^
	~Actor();							//�f�X�g���N�^

	virtual void Update() = 0;						//�X�V
	virtual void Draw(glm::mat4 projection) = 0;	//�`��

protected:

	std::shared_ptr<Window> windowContext;	//�E�C���h�E�R���e�L�X�g

};


#endif