# version 330 core

out vec4 fragColor;

in vec2 textCoor;

uniform sampler2D texture;

void main()
{	
	fragColor = texture(texture, textCoor);
	//fragColor = vec4(0.5, 0.0, 0.0, 1.0);
}