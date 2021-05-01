#include "Transform.hpp"
#include "Actor.hpp"

// ###################### �R���X�g���N�^ ###################### 
Transform::Transform(std::shared_ptr<Window> w) : Actor(w)
{
	//�p�����[�^��������
	vecScale = glm::vec3(1.0f, 1.0f, 1.0f);			//�g��k��
	vecRotate = glm::vec3(1.0f, 1.0f, 1.0f);		//��]
	angle = 0.0f;									//��]��
	vecTranslate = glm::vec3(0.0f, 0.0f, 0.0f);		//���s�ړ�

	//�s���������
	scale = glm::scale(glm::mat4(1), vecScale);
	rotate = glm::rotate(angle, vecRotate);
	translate = glm::translate(glm::mat4(1), vecTranslate);

}



// ###################### Transform�@�ݒ� ###################### 

//�X�P�[��
void Transform::setScale(glm::vec3 s)
{
	vecScale = s;
	scale = glm::scale(glm::mat4(1), vecScale);
}

//��]
void Transform::setRotate(glm::vec3 r, float a)
{
	vecRotate = r;
	angle = a;
	rotate = glm::rotate(angle, vecRotate);
}

//���s�ړ�
void Transform::setTransform(glm::vec3 t)
{	
	vecTranslate = t;
	translate = glm::translate(glm::mat4(1), vecTranslate);
}

// ###################### Transform�@�擾 ###################### 

//�X�P�[��
glm::vec3 Transform::getScale()
{
	return vecScale;
}

//��]
glm::vec3 Transform::getRotate()
{
	return vecRotate;

}

//��]��
float Transform::getRotateAngle()
{
	return angle;

}

//���s�ړ�
glm::vec3 Transform::getTransform()
{
	return vecTranslate;
}


// ###################### �f�X�g���N�^ ###################### 
Transform::~Transform()
{

}
