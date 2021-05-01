#include "Transform_2D.hpp"
#include "Actor.hpp"

// ###################### �R���X�g���N�^ ###################### 
Transform_2D::Transform_2D(std::shared_ptr<Window> w) : Actor(w)
{
	//�p�����[�^��������
	vecScale = glm::vec3(100.0f, 100.0f, 1.0f);			//�g��k��
	vecRotate = glm::vec3(1.0f, 1.0f, 1.0f);		//��]
	angle = 0.0f;									//��]��
	vecTranslate = glm::vec3(0.0f, 0.0f, 0.0f);		//���s�ړ�

	//�s���������
	scale = glm::scale(glm::mat4(1), vecScale);
	rotate = glm::rotate(angle, vecRotate);
	translate = glm::translate(glm::mat4(1), vecTranslate);

}



// ###################### Transform_2D�@�ݒ� ###################### 

//�X�P�[��
void Transform_2D::setScale(glm::vec3 s)
{
	vecScale = s;
	scale = glm::scale(glm::mat4(1), vecScale);
}

//��]
void Transform_2D::setRotate(glm::vec3 r, float a)
{
	vecRotate = r;
	angle = a;
	rotate = glm::rotate(angle, vecRotate);
}

//���s�ړ�
void Transform_2D::setTransform_2D(glm::vec3 t)
{	
	vecTranslate = t;
	translate = glm::translate(glm::mat4(1), vecTranslate);
}

// ###################### Transform_2D�@�擾 ###################### 

//�X�P�[��
glm::vec3 Transform_2D::getScale()
{
	return vecScale;
}

//��]
glm::vec3 Transform_2D::getRotate()
{
	return vecRotate;
}

//��]��
float Transform_2D::getRotateAngle()
{
	return angle;

}

//���s�ړ�
glm::vec3 Transform_2D::getTransform_2D()
{
	return vecTranslate;
}


// ###################### �f�X�g���N�^ ###################### 
Transform_2D::~Transform_2D()
{

}
