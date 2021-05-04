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
	
	void DrawGraph(glm::vec2 pos,glm::mat4 projection,unsigned char texNum);						//�`��
	void DrawRotateGraph(glm::vec2 pos, float angle, glm::mat4 projection, unsigned char texNum);	//��]�`��
	void DrawExtendGraph(glm::vec2 pos,glm::vec2 scale,glm::mat4 projection, unsigned char texNum);	//�X�P�[���`��

	void setTexture(TextureData tex);			//�e�N�X�`���ݒ�

private:

	//���_�z��
	struct Vertex
	{
		GLfloat position[2];	//���W
		GLfloat uv[2];			//UV
	};


	void setDrawTextureID(unsigned char id);	//�`�悷��e�N�X�`���ԍ����w��




	std::vector<TextureData> textureID;	//�e�N�X�`���[ID
	unsigned char textureNumber;	//�e�N�X�`���[ID��I��
	unsigned char textureUnitCount;	//�e�N�X�`���[�ԍ����J�E���g
	GLuint vao;							//VertexArrayObject
	GLuint vbo;							//VertexBufferObject	
};

#endif
