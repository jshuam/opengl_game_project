#version 330 core

in vec2 v_tex_coord;

out vec4 color;

uniform sampler2D u_tex;

void main()
{
	if( v_tex_coord.x > 0.002 && v_tex_coord.x < 0.998 && v_tex_coord.y > 0.002 && v_tex_coord.y < 0.998 )
	{
		color = texture( u_tex, v_tex_coord );
	}
	else
	{
		color = vec4( 1.0, 1.0, 1.0, 1.0 );
	}
};
