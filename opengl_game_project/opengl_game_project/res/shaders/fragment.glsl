#version 330 core

in vec2 v_tex_coord;

out vec4 color;

uniform sampler2D u_tex;

void main()
{
	color = texture(u_tex, v_tex_coord);
};
