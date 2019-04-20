#version 330 core

layout( location = 0 ) in vec4 glyph_coords;
out vec2 tex_coords;

uniform mat4 u_mvp;

void main()
{
	gl_Position = u_mvp *  vec4( glyph_coords.xy, 0.0, 1.0 );
	tex_coords = glyph_coords.zw;
};
