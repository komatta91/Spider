#version 330

in vec2 textCord;
out vec4 fragColor;

uniform sampler2D sampler;
uniform vec3 baseColor;
uniform vec3 ambientLight;

void main()
{
	vec4 totalLight = vec4(ambientLight, 1);
	vec4 color = texture2D(sampler, textCord) * vec4(baseColor, 1.0);

	fragColor = color * totalLight;
}