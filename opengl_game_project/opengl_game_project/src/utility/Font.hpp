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
	struct Character
	{
		unsigned int m_texture;
		long m_advance;
		glm::vec2 m_size;
		glm::vec2 m_bearing;
	};

public:
	Font(std::string fontFilepath, int fontSize);
	glm::vec2 getTextSize(const char* text, float scale) const;

	static inline const auto& getCharacter(const char c) { return m_characters.at(c); }


private:
	static std::map<char, Character> m_characters;

	FT_Library m_ft;
	FT_Face m_face;
};
