#version 330 core

in vec4 vfragment;
out vec4 fragment;


void main()
{
//	fragment = vec4(0.0,0.0,1.0,1.0);
	fragment = vfragment;
}