#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec3 color;
layout(location = 3) in vec2 uv;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

uniform vec3 lightpos;

out vec3 vertex_color;
out vec2 UV;

void main()
{
	UV = uv;
	vec3 light = normalize(lightpos);
	if(normal == vec3(0.0f, 0.0f, 0.0f))
	{
		vertex_color = color;
		gl_Position = projection * view * model * vec4(position, 1.0);
	}
	else
	{
		mat4 normalMat = mat4(inverse(transpose(mat3(model))));
		vec4 n_normal = normalize(normalMat * vec4(normal, 0.0));

		float cos_light = dot(light, n_normal.xyz);

		vertex_color = color * cos_light;
		gl_Position = projection * view * model * vec4(position, 1.0);
	}
}