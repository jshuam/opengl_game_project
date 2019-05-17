#pragma once

#include "glm/ext/vector_float2.hpp"
#include "glm/ext/vector_float3.hpp"
#include "glm/ext/vector_float4.hpp"

#include "Font.hpp"

class Text
{
public:
	Text() = default;
	Text(const char* text, Font* font, glm::vec2 position = {0, 0}, float scale = 1.0f, glm::vec3 color = {1, 1, 1});
	void render() const;

	inline void setPosition(glm::vec2 position) { m_position = position; }
	inline void setScale(float scale) { m_scale = scale; }
	inline void setColor(glm::vec3 color) { m_color = color; }

	inline glm::vec4 getBounds() const { return glm::vec4(m_position.x, m_position.y, m_position.x + m_size.x, m_position.y + m_size.y); }

	inline const int getWidth() const { return m_size.x; }
	inline const int getHeight() const { return m_size.y; }

private:
	const char* m_text;
	Font* m_font;
	glm::vec2 m_position;
	float m_scale;
	glm::vec3 m_color;
	glm::vec2 m_size;
};