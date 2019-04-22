#pragma once

#include "Program.h"
#include "Vertex_Array.h"
#include "Vertex_Buffer.h"
#include "Index_Buffer.h"

#include <ft2build.h>
#include FT_FREETYPE_H

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <map>
#include <unordered_map>

class Font
{
private:
	struct character
	{
		unsigned int texture;
		unsigned int advance;
		glm::vec2 size;
		glm::vec2 bearing;
	};

	std::map<char, character> characters;

	FT_Library ft;
	FT_Face face;

	Program program;

	Vertex_Array vao;
	Vertex_Buffer vbo;

public:
	Font( const char* font_filepath, int font_size );
	glm::vec2 get_text_size( const char* text, float scale ) const;
	void render_text( const char* text, glm::vec2 position, float scale, glm::vec3 color );
};