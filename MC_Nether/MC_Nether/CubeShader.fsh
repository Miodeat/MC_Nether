# version 330 core

out vec4 fragColor;

in vec3 position;
in vec2 textCoor;
in vec3 normal;

uniform sampler2D texture;

// light
uniform vec3 lightPos;
uniform vec3 lightAmbient;
uniform vec3 lightDiffuse;
uniform vec3 lightSpecular;

uniform float matShininess;

// viewing position
uniform vec3 lookPos;

void main()
{	
	vec3 texColor = texture(texture, textCoor).xyz;
	vec3 ambient = lightAmbient * texColor;

   // diffuse
	vec3 lightDir = normalize(lightPos - position);
	vec3 normDir = normalize(normal);
	float dotLN = max(dot(lightDir, normDir), 0.0);
	vec3 diffuse = lightDiffuse * texColor * dotLN;

	// specular
	vec3 reflectDir = normalize(reflect(-lightDir, normDir));
	vec3 viewDir = normalize(lookPos - position);
	float dotRV = max(dot(reflectDir, viewDir), 0.0);
	vec3 specular = lightSpecular * texColor * pow(dotRV, matShininess);

	// phong model result
	vec3 color = ambient + diffuse + specular;
	fragColor = vec4(color, 1.0);
	//fragColor = vec4(0.5f, 0.0f, 0.0f, 1.0f);
}