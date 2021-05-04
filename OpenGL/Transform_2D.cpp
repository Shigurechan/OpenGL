#include "Transform_2D.hpp"
#include "Actor.hpp"

// ###################### �R���X�g���N�^ ###################### 
Transform_2D::Transform_2D()
{
	size = glm::vec2(0,0);

	//�s���������
	scale = glm::scale(glm::mat4(1), glm::vec3(1.0f,1.0f,1.0f));
	rotate = glm::rotate(0.0f,glm::vec3(0.0, 0.0, 1.0));
	translate = glm::translate(glm::mat4(1), glm::vec3(1.0f,1.0f,1.0f));
}

// ###################### Transform_2D�@�ݒ� ###################### 

//�X�P�[��
void Transform_2D::setScale(glm::vec2 s)
{
	scale = glm::scale(glm::mat4(1), glm::vec3(s.x,s.y,0.0f) + glm::vec3(size.x,size.y,0.0f));
}

//��]
void Transform_2D::setRotate(float a)
{
	glm::mat4 m = glm::translate(translate, glm::vec3(size.x * 0.5f, size.y * 0.5f, 0));		//���s�ړ�
	rotate = glm::rotate(m, a, glm::vec3(0.0,0.0,1.0));											//��]	
	m = glm::translate(translate, glm::vec3(-size.x * 0.5f, -size.y * 0.5f, 0));				//���s�ړ�
	rotate = glm::rotate(m, a, glm::vec3(0.0, 0.0, 1.0));										//��]
}

//���s�ړ�
void Transform_2D::setTranslate(glm::vec3 t)
{	
	translate = glm::translate(glm::mat4(1), t);
}

//�摜�T�C�Y��ݒ�
void Transform_2D::setSizeScale(glm::vec2 s)
{
	size = s;
	scale = glm::scale(glm::mat4(1), glm::vec3(s.x, s.y, 0.0f));
}

// ###################### �f�X�g���N�^ ###################### 
Transform_2D::~Transform_2D()
{

}
