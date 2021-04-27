#ifndef ___DRAWTEST_HPP
#define ___DRAWTEST_HPP


#include <iostream>
#include <glew/include/GL/glew.h>

#include <glm/gtx/matrix_transform_2d.hpp>
#include <glm/glm.hpp>


class Shader;
class DrawTest
{
public:
	DrawTest();		//�R���X�g���N�^
	~DrawTest();	//�f�X�g���N�^

	void Update();	//�X�V
	void Draw();	//�`��

private:
	
	std::shared_ptr<Shader> shader;	//�V�F�[�_�[�N���X


	GLuint vao;	//VertexArrayObject
	GLuint vbo;	//VertexBufferObject

	
	//�p�����[�^
	glm::vec3 vecScale;		//�g��k��
	glm::vec3 vecRotate;	//��]
	float angle;			//��]��
	glm::vec3 vecTranslate;	//���s�ړ�


	//�`��s��
	glm::mat4 scale;		//�g��k��
	glm::mat4 rotate;		//��]
	glm::mat4 translate;	//���s�ړ�
	glm::mat4 view;			//�r���[
	glm::mat4 projection;	//�ˌ`
};

#endif
