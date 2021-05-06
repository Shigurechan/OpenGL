/*#########################################################################
# 単色の二次元描画
###########################################################################*/
#version 330

#extension GL_ARB_explicit_attrib_location: enable 


layout(location = 2) in vec2 vUV;	//UV座標	
uniform sampler2D uImage;			//イメージ

//出力
out vec4 fragment;

void main()
{

	fragment = texture(uImage,vUV);
}