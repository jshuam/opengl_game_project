#version 330 core

in vec2 v_tex_coord;

out vec4 color;

uniform sampler2D u_tex;
uniform vec4 u_color;

void main()
{
	vec4 tex_color = texture(u_tex, v_tex_coord);
	color = tex_color;
};
