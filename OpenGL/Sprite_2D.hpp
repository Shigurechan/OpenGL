#ifndef ___Sprite_2D_HPP
#define ___Sprite_2D_HPP


#include <iostream>
#include <glew/include/GL/glew.h>
#include <glm/glm.hpp>

#include "Texture.hpp"
#include "Transform_2D.hpp"
#include "Shader.hpp"



class Sprite_2D : protected Transform_2D, public Shader
{
public:

	Sprite_2D(const char* vert = "Shader/BasicTexture_2D.vert", const char* frag = "Shader/BasicTexture_2D.frag");		//�R���X�g���N�^
	~Sprite_2D();										//�f�X�g���N�^

	// ###################### �����o�֐� ###################### 
	
	void DrawGraph(glm::vec2 pos,glm::mat4 projection);							//�`��
	void DrawRotateGraph(glm::vec2 pos, float angle, glm::mat4 projection);		//��]�`��
	void DrawExtendGraph(glm::vec2 pos,glm::vec2 scale,glm::mat4 projection);	//�X�P�[���`��

	void setTexture(TextureData tex);			//�e�N�X�`���ݒ�
	void setDrawTextureID(unsigned char id);	//�`�悷��e�N�X�`���ԍ����w��

private:

	//���_�z��
	struct Vertex
	{
		GLfloat position[2];	//���W
		GLfloat uv[2];			//UV
	};



	std::vector<TextureData> textureID;	//�e�N�X�`���[ID
	int selectID;						//�e�N�X�`���[ID��I��
	GLuint vao;						//VertexArrayObject
	GLuint vbo;						//VertexBufferObject


	
};

#endif
