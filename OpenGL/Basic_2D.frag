#extension GL_ARB_explicit_attrib_location: enable 


layout(location = 2) in vec4 vfragment;	


//èoóÕ
out vec4 fragment;

void main()
{
	fragment = vfragment;
}