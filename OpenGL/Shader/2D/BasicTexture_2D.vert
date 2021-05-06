/*#########################################################################
# 単色の二次元描画
###########################################################################*/
#version 330
#extension GL_ARB_explicit_attrib_location: enable 




//頂点情報
layout(location = 0) in vec2 vertexPosition;	//頂点座標
layout(location = 1) in vec2 vertexUV;			//UV座標

//フラグメント 転送
layout(location = 2) out vec2 vUV; //UV

uniform mat4 uScale;		//スケール
uniform mat4 uRotate;		//回転
uniform mat4 uTranslate;	//平行移動

uniform mat4 uViewProjection;	//ビュープロジェクション行列




void main()
{
	vec4 vertex = vec4(vertexPosition,0.0,1.0);		//頂点座標
	mat4 model = uTranslate * uRotate * uScale;		//モデル行列
	gl_Position =  (uViewProjection * model) * vertex;
	
	


	vUV = vertexUV;	//UV座標
}