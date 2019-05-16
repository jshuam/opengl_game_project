#include "Text.hpp"

Text::Text(const char* text, Font* font, glm::vec2 position, float scale, glm::vec3 color)
	:
	m_text(text),
	m_font(font),
	m_position(position),
	m_scale(scale),
	m_color(color),
	m_size(font->getTextSize(text, scale))
{}

void Text::render() const
{
	m_font->renderText(m_text, m_position, m_scale, m_color);
}
