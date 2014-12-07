#version 330

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 inTextCord;
layout (location = 2) in vec3 inNormal;


out vec2 textCord;
out vec3 normal;
out vec3 worldPos;


uniform mat4 transform;
uniform mat4 transformProjected;

void main()
{
	textCord = inTextCord;
	normal = (transform * vec4(inNormal, 0.0)).xyz;
	worldPos = (transform * vec4(position, 1.0)).xyz;
	gl_Position = transformProjected * vec4( position, 1.0);
}