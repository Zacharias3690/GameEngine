#version 330 core

uniform mat4 projection;
uniform mat4 model;
uniform mat4 view;

in vec3 vert;
in vec2 uv;
in vec3 norm;

out vec2 frag_uv;
out vec3 frag_norm;

void main()
{	
	gl_Position = projection * view * model * vec4(vert,1);
	frag_uv = uv;
	frag_norm = norm;
}