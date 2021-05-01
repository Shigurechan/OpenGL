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
	�S�Ă̕`�敨�͂�����p������
###########################################################################*/

class Transform_2D : public Actor
{
public:

	Transform_2D(std::shared_ptr<Window> w);	//�R���X�g���N�^
	~Transform_2D();							//�f�X�g���N�^



	// ###################### Transform_2D�@�ݒ� ###################### 
	void setScale(glm::vec3 s);				//�X�P�[��
	void setRotate(glm::vec3 r,float a);	//��]
	void setTransform_2D(glm::vec3 t);			//���s�ړ�

	// ###################### Transform_2D�@�擾 ###################### 
	glm::vec3 getScale();		//�X�P�[��
	glm::vec3 getRotate();		//��]
	float getRotateAngle();		//��]��
	glm::vec3 getTransform_2D();	//���s�ړ�


protected:

	

	//�`��s��
	glm::mat4 scale;		//�g��k��
	glm::mat4 rotate;		//��]
	glm::mat4 translate;	//���s�ړ�
	

private:
	//�p�����[�^
	glm::vec3 vecScale;		//�g��k��
	glm::vec3 vecRotate;	//��]
	float angle;			//��]��
	glm::vec3 vecTranslate;	//���s�ړ�


};


#endif