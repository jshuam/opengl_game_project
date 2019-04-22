#version 330 core

layout( location = 0 ) in vec4 position;

out vec2 v_tex_coord;

uniform mat4 u_mvp;

void main()
{
	gl_Position = u_mvp *  vec4( position.xy, 0.0, 1.0 );
	v_tex_coord = position.zw;
};
