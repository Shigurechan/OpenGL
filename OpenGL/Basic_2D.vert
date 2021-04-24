in vec2 position;	//���_���W


uniform mat3 uScale;		//�X�P�[��
uniform mat3 uRotate;		//��]
uniform mat3 uTranslate;	//���s�ړ�
uniform mat3 simpleView;	//�ˌ`�s��


uniform vec4 uFragment;	//�F

out vec4 vFragment;

void main()
{

	mat3 worldView = uScale * uRotate * uTranslate;
	vec3 pos = vec3(position.x,position.y,0.0) * worldView * simpleView;
	gl_Position =  vec4(pos,0.0);	//���W


	vFragment = uFragment;								//�J���[
}