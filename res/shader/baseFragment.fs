#version 330

in vec2 textCord;
out vec4 fragColor;

uniform sampler2D sampler;
uniform vec3 color;
void main()
{
	fragColor = texture2D(sampler, textCord) * vec4(color, 1.0);
	//fragColor = vec4(color, 0.0f);
	//fragColor = vec4(1.0, 0, 0, 0);
	//gl_FragColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);

}