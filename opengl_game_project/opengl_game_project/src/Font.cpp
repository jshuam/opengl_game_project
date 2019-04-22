#include "Font.h"
#include "Renderer.h"
#include "Program.h"
#include "Shader.h"

#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

Font::Font( const char* font_filepath, int font_size )
	:
	vbo( { sizeof( float ) * 6 * 4, nullptr, 4, GL_FLOAT, GL_FALSE, GL_DYNAMIC_DRAW } )
{
	if( FT_Init_FreeType( &ft ) )
	{
		std::cout << "[ERROR] Could not load FreeType library" << std::endl;
		std::cin.get();
		exit( -1 );
	}

	if( FT_New_Face( ft, font_filepath, 0, &face ) )
	{
		std::cout << "[ERROR] Could not load font" << std::endl;
		std::cin.get();
		exit( -1 );
	}

	FT_Set_Pixel_Sizes( face, 0, font_size );

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

	Shader vertex_shader( GL_VERTEX_SHADER, "res/shaders/font_vertex.glsl" );
	Shader fragment_shader( GL_FRAGMENT_SHADER, "res/shaders/font_fragment.glsl" );

	program.attach_shader( vertex_shader );
	program.attach_shader( fragment_shader );
	program.compile();
	program.bind();

	glm::mat4 proj = glm::ortho( 0.0f, 1280.0f, 0.0f, 720.0f, -1.0f, 1.0f );

	program.set_uniform_mat4f( "u_mvp", proj );

	vao.add_buffer( vbo );

}

glm::vec2 Font::get_text_size( const char* text, float scale ) const
{
	glm::vec2 size( 0.0f, 0.0f );
	for( const char* i = &text[0]; *i != '\0'; i++ )
	{
		character c = characters.at( *i );

		size.x += ( c.advance / 64 ) * scale;

		if( size.y < c.size.y * scale ) size.y = c.size.y * scale;
	}

	return size;
}

void Font::render_text( const char* text, glm::vec2 position, float scale, glm::vec3 color )
{
	program.bind();
	program.set_uniform_3f( "u_tex_color", color.x, color.y, color.z );
	glActiveTexture( GL_TEXTURE0 );
	vao.bind();

	for( const char* i = &text[0]; *i != '\0'; i++ )
	{
		character c = characters.at( *i );

		float x_pos = position.x * scale;
		float y_pos = position.y - ( c.size.y - c.bearing.y ) * scale;

		float width = c.size.x * scale;
		float height = c.size.y * scale;

		// Update VBO for each character
		GLfloat vertices[6][4] =
		{
			{ x_pos, y_pos + height, 0.0f, 0.0f },
		{ x_pos, y_pos, 0.0f, 1.0f },
		{ x_pos + width, y_pos, 1.0f, 1.0f },
		{ x_pos, y_pos + height, 0.0f, 0.0f },
		{ x_pos + width, y_pos, 1.0f, 1.0f },
		{ x_pos + width, y_pos + height, 1.0f, 0.0f }
		};

		// Render glyph texture over quad
		glBindTexture( GL_TEXTURE_2D, c.texture );

		// Update content of VBO memory
		vbo.modify_buffer( sizeof( vertices ), vertices );

		// Render quad
		glDrawArrays( GL_TRIANGLES, 0, 6 );

		// Now advance cursors for next glyph (note that advance is number of 1/64 pixels)
		position.x += ( c.advance >> 6 ) * scale; // Bitshift by 6 to get value in pixels (2^6 = 64)
	}
	glBindVertexArray( 0 );
	glBindTexture( GL_TEXTURE_2D, 0 );
}
