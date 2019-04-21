#pragma once

#include "Font.h"

#include <glm/vec2.hpp>

class Text
{
private:
	const char* text;
	glm::vec2 size;
	glm::vec2 position;
	float scale;
	glm::vec3 color;
	Font* font;

public:
	Text( const char* text, glm::vec2 position, float scale, glm::vec3 color, Font* font );
	void render() const;
};