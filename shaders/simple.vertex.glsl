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

	mat4 normalMat = transpose(inverse(model));
	// vec3 n_normal = (normalMat * vec4(normal, 1.0)).xyz;
	vec3 n_normal = normal;

	float cosTheta = dot(light, n_normal);
	vec3 l_color = cosTheta * vec3(1.0, 1.0, 1.0);

	vertex_color = color * cosTheta;
	gl_Position = projection * view * model * vec4(position, 1.0);
}