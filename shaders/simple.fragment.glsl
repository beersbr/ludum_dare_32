#version 330 core

in vec3 vertex_color;
in vec2 UV;
out vec4 final_color;

uniform sampler1D jupiter1D;

void main()
{
	final_color = vec4(vertex_color, 1.0) * vec4(texture(jupiter1D, UV.y).rgb, 1.0);
}