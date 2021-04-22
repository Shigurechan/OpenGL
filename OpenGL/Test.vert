#version 330 core

in vec2 position;
//in vec4 fragment;

uniform vec4 ufragment;

out vec4 out_fragment;

void main()
{
	gl_Position =  vec4(position.x,position.y,1.0,1.0);	//ç¿ïW
//	vfragment = fragment;
	out_fragment = ufragment;
}