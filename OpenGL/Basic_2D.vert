in vec2 position;	//頂点座標


uniform mat3 uScale;		//スケール
uniform mat3 uRotate;		//回転
uniform mat3 uTranslate;	//平行移動
uniform mat3 simpleView;	//射形行列


uniform vec4 uFragment;	//色

out vec4 vFragment;

void main()
{

	mat3 worldView = uScale * uRotate * uTranslate;
	vec3 pos = vec3(position.x,position.y,0.0) * worldView * simpleView;
	gl_Position =  vec4(pos,0.0);	//座標


	vFragment = uFragment;								//カラー
}