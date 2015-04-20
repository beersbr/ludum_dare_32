#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec3 color;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

uniform vec3 lightpos;

out vec3 vertex_color;

void main()
{
	// vec3 light = normalize(vec3(-1.0f, 1.0f, 1.0f));
	vec3 light = normalize(lightpos);

	mat4 normalMat = mat4(inverse(transpose(mat3(model))));
	vec4 n_normal = normalize(normalMat * vec4(normal, 0.0));

	float cosTheta = dot(light, n_normal.xyz);

	vertex_color = color * cosTheta;
	gl_Position = projection * view * model * vec4(position, 1.0);
}