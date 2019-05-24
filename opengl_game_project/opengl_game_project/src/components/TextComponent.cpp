#include "TextComponent.hpp"

Text::Text(const char* text, std::unique_ptr<Font> font)
	:
	m_text(text),
	m_font(std::move(font))
{}
