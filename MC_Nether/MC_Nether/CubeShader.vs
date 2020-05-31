# version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTextCoor;
layout (location = 2) in vec3 aNormal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 position;
out vec2 textCoor;
out vec3 normal;

void main()
{
	position = aPos;
	gl_Position = projection * view * model * vec4(aPos, 1.0);
	textCoor = aTextCoor;
	normal = aNormal;
}