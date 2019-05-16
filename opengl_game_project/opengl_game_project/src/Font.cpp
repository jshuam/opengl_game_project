#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>

#include "../gl/objects/program.hpp"
#include "../gl/objects/shader.hpp"
#include "Font.hpp"

Font::Font(std::string fontFilepath, int fontSize)
	:
	m_vbo({sizeof(float) * 6 * 4, nullptr, 4, GL_FLOAT, GL_FALSE, GL_DYNAMIC_DRAW})
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

	Shader vertex_shader(GL_VERTEX_SHADER, "res/shaders/font_vertex.glsl");
	Shader fragment_shader(GL_FRAGMENT_SHADER, "res/shaders/font_fragment.glsl");

	m_program.attachShader(vertex_shader);
	m_program.attachShader(fragment_shader);
	m_program.compile();
	m_program.bind();

	glm::mat4 proj = glm::ortho(0.0f, 1280.0f, 0.0f, 720.0f, -1.0f, 1.0f);

	m_program.setUniformMat4f("u_mvp", proj);
	m_vao.addBuffer(m_vbo);

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

void Font::renderText(const char* text, glm::vec2 position, float scale, glm::vec3 color)
{
	m_program.bind();
	m_program.setUniform3f("u_tex_color", color.x, color.y, color.z);
	glActiveTexture(GL_TEXTURE0);
	m_vao.bind();

	for(const char* i = &text[0]; *i != '\0'; i++)
	{
		Character c = m_characters.at(*i);

		float x_pos = position.x * scale;
		float y_pos = position.y - (c.m_size.y - c.m_bearing.y) * scale;

		float width = c.m_size.x * scale;
		float height = c.m_size.y * scale;

		// Update VBO for each Character
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
		glBindTexture(GL_TEXTURE_2D, c.m_texture);

		// Update content of VBO memory
		m_vbo.modifyBuffer(sizeof(vertices), vertices);

		// Render quad
		glDrawArrays(GL_TRIANGLES, 0, 6);

		// Now m_advance cursors for next glyph (note that m_advance is number of 1/64 pixels)
		position.x += (c.m_advance >> 6) * scale; // Bit shift by 6 to get value in pixels (2^6 = 64)
	}
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);
}
