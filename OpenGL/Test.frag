#version 330 core

in vec4 in_fragment;
out vec4 out_fragment;

void main()
{
//	fragment = vec4(0.0,0.0,1.0,1.0);
	out_fragment = in_fragment;
}