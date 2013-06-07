#version 330 core

in vec2 frag_uv;
in vec3 frag_norm;

out vec3 color;

uniform sampler2D sampler;

void main()
{
	color = texture(sampler, frag_uv).rgba;
}