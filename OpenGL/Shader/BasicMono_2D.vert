/*#########################################################################
# �P�F�̓񎟌��`��
###########################################################################*/
#extension GL_ARB_explicit_attrib_location: enable 




//���_���
layout(location = 0) in vec2 vertexPosition;	//���_���W

//�t���O�����g�ɓ]��
layout(location = 2) out vec4 vFragment;	//���_�J���[



uniform mat4 uScale;		//�X�P�[��
uniform mat4 uRotate;		//��]
uniform mat4 uTranslate;	//���s�ړ�

uniform mat4 uViewProjection;	//�r���[�v���W�F�N�V�����s��
//uniform mat4 uView;			//�r���[�s��

uniform vec4 uFragment;	//�F


void main()
{
	vec4 vertex = vec4(vertexPosition,0.0,1.0);		//���_���W
	mat4 model = uTranslate * uRotate * uScale;		//���f���s��
	gl_Position =  (uViewProjection * model) * vertex;
	
	


	vFragment = uFragment;				//�J���[
}