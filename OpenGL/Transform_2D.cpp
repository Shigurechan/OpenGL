#include "Transform_2D.hpp"
#include "Actor.hpp"

// ###################### �R���X�g���N�^ ###################### 
Transform_2D::Transform_2D(std::shared_ptr<Window> w) : Actor(w)
{
	//�p�����[�^��������
	vecScale = glm::vec3(0.0f, 0.0f, 0.0f);			//�g��k��
	vecSize = glm::vec3(0.0,0.0,0.0);				//�摜�T�C�Y
	
	angle = 0.0f;									//��]��
	vecTranslate = glm::vec3(0.0f,0.0f, 0.0f);	//���s�ړ�

	//�s���������
	scale = glm::scale(glm::mat4(1), vecScale);
	rotate = glm::rotate(angle, glm::vec3(0.0, 0.0, 1.0));
	translate = glm::translate(glm::mat4(1), vecTranslate);
}



// ###################### Transform_2D�@�ݒ� ###################### 

//�X�P�[��
void Transform_2D::setScale(glm::vec3 s)
{
	vecScale = s;
	scale = glm::scale(glm::mat4(1), vecScale + vecSize);
}

//��]
void Transform_2D::setRotate(float a)
{
	
	angle = a;

	glm::mat4 m = glm::translate(translate, glm::vec3(vecSize.x * 0.5f, vecSize.y * 0.5f, 0));		//���s�ړ�
	rotate = glm::rotate(m, angle, glm::vec3(0.0,0.0,1.0));											//��]	
	m = glm::translate(translate, glm::vec3(-vecSize.x * 0.5f, -vecSize.y * 0.5f, 0));				//���s�ړ�
	rotate = glm::rotate(m, angle, glm::vec3(0.0, 0.0, 1.0));										//��]
}

//���s�ړ�
void Transform_2D::setTranslate(glm::vec3 t)
{	
	vecTranslate = t;
	translate = glm::translate(glm::mat4(1), vecTranslate);
}

//�摜�T�C�Y��ݒ�
void Transform_2D::setSizeScale(glm::vec2 s)
{
	vecSize = glm::vec3(s.x,s.y,0.0);
	scale = glm::scale(glm::mat4(1), vecSize);

}





// ###################### Transform_2D�@�擾 ###################### 

//�X�P�[��
glm::vec3 Transform_2D::getScale()
{
	return vecScale;
}

//��]��
float Transform_2D::getRotateAngle()
{
	return angle;

}

//���s�ړ�
glm::vec3 Transform_2D::getTranslate()
{
	return vecTranslate;
}


// ###################### �f�X�g���N�^ ###################### 
Transform_2D::~Transform_2D()
{

}
