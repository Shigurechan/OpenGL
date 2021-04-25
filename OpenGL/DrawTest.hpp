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

	//�X�P�[��
	glm::mat3 scale;

	//��]
	glm::mat3 rotate;

	//���s�ړ�
	glm::mat3 translate;

	//�ˌ`�s��
	float sv[9];
	glm::mat3 simpleView;


};

#endif
