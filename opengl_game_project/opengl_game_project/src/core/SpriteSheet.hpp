#pragma once

#include "../gl/drawables/texture.hpp"

class SpriteSheet
{
public:
	SpriteSheet(Texture texture, float width, float height);

	inline float getWidth();

private:
	Texture m_texture;
	float m_width, m_height;
};