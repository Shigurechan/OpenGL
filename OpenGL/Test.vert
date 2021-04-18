in vec4 position;
uniform float aspect;
void main()
{
	gl_Position =  vec4(1.0 / aspect,1.0,1.0,1.0) * position;
}