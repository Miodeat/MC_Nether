# version 330 core

out vec4 fragColor;

in vec2 textCoor;

uniform sampler2D texture;

void main()
{	
	fragColor = texture(texture, textCoor);
	//fragColor = vec4(0.5f, 0.0f, 0.0f, 1.0f);
}