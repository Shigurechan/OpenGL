#ifndef ___TRANSFORM_HPP_
#define ___TRANSFORM_HPP_

#include <iostream>
#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>

#include "Actor.hpp"


class Window;
/*#########################################################################
# �g�����X�t�H�[���N���X: Actor�N���X���p��

����
	�S�Ă̕`�敨�͂�����p������
###########################################################################*/

class Transform : public Actor
{
public:

	Transform(std::shared_ptr<Window> w);	//�R���X�g���N�^
	~Transform();							//�f�X�g���N�^



	// ###################### Transform�@�ݒ� ###################### 
	void setScale(glm::vec3 s);				//�X�P�[��
	void setRotate(glm::vec3 r,float a);	//��]
	void setTransform(glm::vec3 t);			//���s�ړ�

	// ###################### Transform�@�擾 ###################### 
	glm::vec3 getScale();		//�X�P�[��
	glm::vec3 getRotate();		//��]
	float getRotateAngle();		//��]��
	glm::vec3 getTransform();	//���s�ړ�


protected:

	//�p�����[�^
	glm::vec3 vecScale;		//�g��k��
	glm::vec3 vecRotate;	//��]
	float angle;			//��]��
	glm::vec3 vecTranslate;	//���s�ړ�


	//�`��s��
	glm::mat4 scale;		//�g��k��
	glm::mat4 rotate;		//��]
	glm::mat4 translate;	//���s�ړ�
	


};


#endif
