/*#########################################################################
# 単色の3D描画
###########################################################################*/
#extension GL_ARB_explicit_attrib_location: enable 


layout(location = 2) in vec4 vfragment;	


//出力
out vec4 fragment;

void main()
{
	fragment = vfragment;
}