#version 330

in vec2 textCord;
out vec4 fragColor;

uniform sampler2D sampler;
uniform vec3 color;
void main()
{
	fragColor = texture2D(sampler, textCord) * vec4(color, 1.0);
}