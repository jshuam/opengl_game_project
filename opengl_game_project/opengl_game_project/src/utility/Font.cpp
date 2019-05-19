#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>

#include "../gl/objects/Program.hpp"
#include "../gl/objects/Shader.hpp"
#include "Font.hpp"

std::map<char, Font::Character> Font::m_characters;

Font::Font(std::string fontFilepath, int fontSize)
{
	if(FT_Init_FreeType(&m_ft))
	{
		std::cout << "[ERROR] Could not load FreeType library" << std::endl;
		std::cin.get();
		exit(-1);
	}

	if(FT_New_Face(m_ft, "res/fonts/Roboto/Roboto-Thin.ttf", 0, &m_face))
	{
		std::cout << "[ERROR] Could not load font" << std::endl;
		std::cin.get();
		exit(-1);
	}

	FT_Set_Pixel_Sizes(m_face, 0, fontSize);

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	for(unsigned char c = 0; c < 128; c++)
	{
		if(FT_Load_Char(m_face, c, FT_LOAD_RENDER))
		{
			std::cout << "[WARNING] Could not load glyph: " << c << std::endl;
			continue;
		}

		unsigned int texture;
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexImage2D(GL_TEXTURE_2D,
					 0,
					 GL_RED,
					 m_face->glyph->bitmap.width,
					 m_face->glyph->bitmap.rows,
					 0,
					 GL_RED,
					 GL_UNSIGNED_BYTE,
					 m_face->glyph->bitmap.buffer
		);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		Character glyph =
		{
			texture,
			m_face->glyph->advance.x,
			glm::vec2(m_face->glyph->bitmap.width, m_face->glyph->bitmap.rows),
			glm::vec2(m_face->glyph->bitmap_left, m_face->glyph->bitmap_top)
		};

		m_characters.insert(std::pair<char, Character>(c, glyph));
	}

	FT_Done_Face(m_face);
	FT_Done_FreeType(m_ft);
}

glm::vec2 Font::getTextSize(const char* text, float scale) const
{
	glm::vec2 size(0.0f, 0.0f);
	for(const char* i = &text[0]; *i != '\0'; i++)
	{
		Character c = m_characters.at(*i);

		size.x += (c.m_advance / 64) * scale;

		if(size.y < c.m_size.y * scale) size.y = c.m_size.y * scale;
	}

	return size;
}
