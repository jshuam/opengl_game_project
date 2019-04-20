#pragma once

#include "program.h"
#include "vertex_array.h"
#include "vertex_buffer.h"
#include "vertex_buffer_layout.h"

#include <ft2build.h>
#include FT_FREETYPE_H

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <map>

class font_renderer
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

	program program;

	unsigned int vao, vbo;

public:
	font_renderer();
	~font_renderer();

	void render_text( std::string text, float x, float y, float scale, glm::vec3 color );
};