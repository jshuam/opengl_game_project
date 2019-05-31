#include "SpriteSheet.hpp"

SpriteSheet::SpriteSheet(Texture texture, float width, float height)
	:
	m_texture(std::move(texture)),
	m_width(width),
	m_height(height)
{}
