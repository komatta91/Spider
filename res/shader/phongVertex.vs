#version 330

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 inTextCord;


out vec2 textCord;


uniform mat4 transform;

void main()
{
	textCord = inTextCord;
	gl_Position = transform * vec4( position, 1.0);
}