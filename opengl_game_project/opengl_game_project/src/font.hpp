#pragma once

#include <ft2build.h>
#include FT_FREETYPE_H
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

#include <map>
#include <string>
#include <unordered_map>

#include "../gl/objects/Program.hpp"
#include "../gl/drawables/VertexArray.hpp"
#include "../gl/drawables/VertexBuffer.hpp"
#include "../gl/drawables/IndexBuffer.hpp"

class Font
{
public:
	Font(std::string fontFilepath, int fontSize);
	glm::vec2 getTextSize(const char* text, float scale) const;
	void renderText(const char* text, glm::vec2 position, float scale, glm::vec3 color);

private:
	struct Character
	{
		unsigned int m_texture;
		unsigned int m_advance;
		glm::vec2 m_size;
		glm::vec2 m_bearing;
	};

	std::map<char, Character> m_characters;

	FT_Library m_ft;
	FT_Face m_face;

	Program m_program;

	VertexArray m_vao;
	VertexBuffer m_vbo;
};
