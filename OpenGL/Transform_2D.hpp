#ifndef ___Transform_2D_HPP_
#define ___Transform_2D_HPP_

#include <iostream>
#include "glm/glm.hpp"
#include <glm/gtc/matrix_Transform.hpp>
#include <glm/gtx/Transform.hpp>

#include "Actor.hpp"


class Window;
/*#########################################################################
# �g�����X�t�H�[���N���X: Actor�N���X���p��

����
	�S�Ă�2D�`�敨�͂�����p������
###########################################################################*/

class Transform_2D
{
public:

	Transform_2D();		//�R���X�g���N�^
	~Transform_2D();	//�f�X�g���N�^



	// ###################### Transform_2D�@�ݒ� ###################### 
	void setScale(glm::vec2 s);				//�X�P�[��
	void setRotate(float a);				//��]
	void setTranslate(glm::vec3 t);			//���s�ړ�

protected:

	void setSizeScale(glm::vec2 s);	//�X�v���C�g�̃T�C�Y��ݒ�

	//�`��s��
	glm::mat4 scale;		//�g��k��
	glm::mat4 rotate;		//��]
	glm::mat4 translate;	//���s�ړ�
	

private:
	glm::vec2 size;

};


#endif
