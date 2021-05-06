#ifndef ___CIRCLE_HPP_
#define ___CIRCLE_HPP_

#include <iostream>
#include <vector>
#include "Shader.hpp"
#include "Transform_2D.hpp"

class Window;

class Circle : protected Transform_2D, public Shader
{
public:
	Circle(std::shared_ptr<Window> w,const char* vert = NULL,const char* frag = NULL);		//�R���X�g���N�^
	~Circle();								//�f�X�g���N�^

	void Draw(glm::vec2 pos,int num,float r, glm::vec4 color);	//�`��


private:
	std::shared_ptr<Window> windowContext;	//�E�C���h�E�R���e�L�X�g
	bool isDefaultShader;

	std::vector<Transform_2D::VertexColor> vertex;
	int count = 0;

};


#endif;


