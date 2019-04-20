#include "font_renderer.h"
#include "renderer.h"
#include "program.h"
#include "shader.h"

#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

font_renderer::font_renderer()
{
	if( FT_Init_FreeType( &ft ) )
	{
		std::cout << "[ERROR] Could not load FreeType library" << std::endl;
		std::cin.get();
		exit( -1 );
	}

	if( FT_New_Face( ft, "res/fonts/Roboto/Roboto-Thin.ttf", 0, &face ) )
	{
		std::cout << "[ERROR] Could not load font" << std::endl;
		std::cin.get();
		exit( -1 );
	}

	FT_Set_Pixel_Sizes( face, 0, 48 );

	glPixelStorei( GL_UNPACK_ALIGNMENT, 1 );

	for( unsigned char c = 0; c < 128; c++ )
	{
		if( FT_Load_Char( face, c, FT_LOAD_RENDER ) )
		{
			std::cout << "[WARNING] Could not load glyph: " << c << std::endl;
			continue;
		}

		unsigned int texture;
		glGenTextures( 1, &texture );
		glBindTexture( GL_TEXTURE_2D, texture );
		glTexImage2D( GL_TEXTURE_2D,
					  0,
					  GL_RED,
					  face->glyph->bitmap.width,
					  face->glyph->bitmap.rows,
					  0,
					  GL_RED,
					  GL_UNSIGNED_BYTE,
					  face->glyph->bitmap.buffer
		);

		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

		character glyph =
		{
			texture,
			face->glyph->advance.x,
			glm::vec2( face->glyph->bitmap.width, face->glyph->bitmap.rows ),
			glm::vec2( face->glyph->bitmap_left, face->glyph->bitmap_top )
		};

		characters.insert( std::pair<char, character>( c, glyph ) );
	}

	FT_Done_Face( face );
	FT_Done_FreeType( ft );

	shader vertex_shader( GL_VERTEX_SHADER, "res/shaders/font_vertex.glsl" );
	shader fragment_shader( GL_FRAGMENT_SHADER, "res/shaders/font_fragment.glsl" );

	program.attach_shader( vertex_shader );
	program.attach_shader( fragment_shader );
	program.compile();
	program.bind();

	glm::mat4 proj = glm::ortho( 0.0f, 1280.0f, 0.0f, 720.0f, -1.0f, 1.0f );

	program.set_uniform_mat4f( "u_mvp", proj );

	glGenVertexArrays( 1, &vao );
	glGenBuffers( 1, &vbo );
	glBindVertexArray( vao );
	glBindBuffer( GL_ARRAY_BUFFER, vbo );
	glBufferData( GL_ARRAY_BUFFER, sizeof( GLfloat ) * 6 * 4, NULL, GL_DYNAMIC_DRAW );
	glEnableVertexAttribArray( 0 );
	glVertexAttribPointer( 0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof( GLfloat ), 0 );
	glBindBuffer( GL_ARRAY_BUFFER, 0 );
	glBindVertexArray( 0 );

}

font_renderer::~font_renderer()
{}

void font_renderer::render_text( std::string text, float x, float y, float scale, glm::vec3 color )
{
	program.bind();
	program.set_uniform_3f( "u_tex_color", color.x, color.y, color.z );
	glActiveTexture( GL_TEXTURE0 );
	glBindVertexArray( vao );

	std::string::const_iterator c;

	for( c = text.begin(); c != text.end(); c++ )
	{
		character ch = characters[*c];

		GLfloat xpos = x + ch.bearing.x * scale;
		GLfloat ypos = y - ( ch.size.y - ch.bearing.y ) * scale;

		GLfloat w = ch.size.x * scale;
		GLfloat h = ch.size.y * scale;
		// Update VBO for each character
		GLfloat vertices[6][4] = {
			{ xpos,     ypos + h,   0.0, 0.0 },
			{ xpos,     ypos,       0.0, 1.0 },
			{ xpos + w, ypos,       1.0, 1.0 },

			{ xpos,     ypos + h,   0.0, 0.0 },
			{ xpos + w, ypos,       1.0, 1.0 },
			{ xpos + w, ypos + h,   1.0, 0.0 }
		};
		// Render glyph texture over quad
		glBindTexture( GL_TEXTURE_2D, ch.texture );
		// Update content of VBO memory
		glBindBuffer( GL_ARRAY_BUFFER, vbo );
		glBufferSubData( GL_ARRAY_BUFFER, 0, sizeof( vertices ), vertices );
		glBindBuffer( GL_ARRAY_BUFFER, 0 );
		// Render quad
		glDrawArrays( GL_TRIANGLES, 0, 6 );
		// Now advance cursors for next glyph (note that advance is number of 1/64 pixels)
		x += ( ch.advance >> 6 ) * scale; // Bitshift by 6 to get value in pixels (2^6 = 64)
	}
	glBindVertexArray( 0 );
	glBindTexture( GL_TEXTURE_2D, 0 );
}
