#extension GL_ARB_explicit_attrib_location: enable 


layout(location = 2) in vec4 vfragment;	


//èoóÕ
out vec4 fragment;

void main()
{

	fragment = vfragment;
	//fragment = vec4(0.0,0.0,1.0,1.0);

}