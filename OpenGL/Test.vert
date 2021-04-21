#version 330 core

in vec2 position;
in vec4 fragment;

out vec4 vfragment;

void main()
{
	gl_Position =  vec4(position.x,position.y,1.0,1.0);	//ç¿ïW
	vfragment = fragment;
}