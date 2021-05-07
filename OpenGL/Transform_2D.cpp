#include "Transform_2D.hpp"
#include "Actor.hpp"

// ###################### �R���X�g���N�^ ###################### 
FrameWork::Transform_2D::Transform_2D()
{
	size = glm::vec2(0,0);
	vao = 0;
	vbo = 0;
	isDefaultShader = false;

	//�s���������
	scale = glm::scale(glm::mat4(1), glm::vec3(1.0f,1.0f,1.0f));
	rotate = glm::rotate(0.0f,glm::vec3(0.0, 0.0, 1.0));
	translate = glm::translate(glm::mat4(1), glm::vec3(0.0f,0.0f,0.0f));
}

// ###################### �����o�֐� ###################### 

//�X�P�[��
void FrameWork::Transform_2D::setScale(glm::vec2 s)
{
	scale = glm::scale(glm::mat4(1), glm::vec3(s.x,s.y,0.0f) + glm::vec3(size.x,size.y,0.0f));
}

//��]
void FrameWork::Transform_2D::setRotate(float a)
{
	glm::mat4 m = glm::translate(translate, glm::vec3(size.x * 0.5f, size.y * 0.5f, 0));		//���s�ړ�
	rotate = glm::rotate(m, a, glm::vec3(0.0,0.0,1.0));											//��]	
	m = glm::translate(translate, glm::vec3(-size.x * 0.5f, -size.y * 0.5f, 0));				//���s�ړ�
	rotate = glm::rotate(m, a, glm::vec3(0.0, 0.0, 1.0));										//��]
}

//���s�ړ�
void FrameWork::Transform_2D::setTranslate(glm::vec3 t)
{	
	translate = glm::translate(glm::mat4(1), t);
}

//�摜�T�C�Y��ݒ�
void FrameWork::Transform_2D::setSizeScale(glm::vec2 s)
{
	size = s;
	scale = glm::scale(glm::mat4(1), glm::vec3(s.x, s.y, 0.0f));
}

//�摜�T�C�Y��ݒ�
glm::vec2 FrameWork::Transform_2D::getSizeScale()
{
	return size;
	
}

// ###################### �f�X�g���N�^ ###################### 
FrameWork::Transform_2D::~Transform_2D()
{

}
