in vec2 position;

in vec4 fragColor;
out vec4 vfragColor;

void main()
{
	gl_Position =  vec4(position.x,position.y,1.0,1.0);	//ç¿ïW
	vfragColor = fragColor;								//ÉJÉâÅ[
}