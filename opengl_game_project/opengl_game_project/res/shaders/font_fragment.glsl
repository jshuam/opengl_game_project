#version 330 core

in vec2 v_tex_coord;

out vec4 color;

uniform sampler2D u_tex;
uniform vec3 u_tex_color;

void main()
{
	vec4 sampled = vec4( 1.0, 1.0, 1.0, texture( u_tex, v_tex_coord).r );
	color = vec4( u_tex_color, 1.0 ) * sampled;
};
