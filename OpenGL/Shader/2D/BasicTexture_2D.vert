/*#########################################################################
# �P�F�̓񎟌��`��
###########################################################################*/
#version 330
#extension GL_ARB_explicit_attrib_location: enable 




//���_���
layout(location = 0) in vec2 vertexPosition;	//���_���W
layout(location = 1) in vec2 vertexUV;			//UV���W

//�t���O�����g �]��
layout(location = 2) out vec2 vUV; //UV

uniform mat4 uScale;		//�X�P�[��
uniform mat4 uRotate;		//��]
uniform mat4 uTranslate;	//���s�ړ�

uniform mat4 uViewProjection;	//�r���[�v���W�F�N�V�����s��




void main()
{
	vec4 vertex = vec4(vertexPosition,0.0,1.0);		//���_���W
	mat4 model = uTranslate * uRotate * uScale;		//���f���s��
	gl_Position =  (uViewProjection * model) * vertex;
	
	


	vUV = vertexUV;	//UV���W
}