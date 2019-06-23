#include "TextComponent.hpp"

TextComponent::TextComponent(const char* text, std::unique_ptr<Font> font) : m_text(text), m_font(std::move(font))
{
}