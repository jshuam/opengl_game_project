#pragma once

#include "Font.h"

#include <glm/vec2.hpp>
#include <glm/vec4.hpp>

class Text
{
private:
	const char* text;
	Font* font;
	glm::vec2 position;
	float scale;
	glm::vec3 color;
	glm::vec2 size;

public:
	Text( const char* text, Font* font, glm::vec2 position = { 0, 0 }, float scale = 0.0f, glm::vec3 color = { 0, 0, 0 } );
	void render() const;

	inline void set_position( glm::vec2 position ) { this->position = position; }
	inline void set_scale( float scale ) { this->scale = scale; }
	inline void set_color( glm::vec3 color ) { this->color = color; }

	inline glm::vec4 get_bounds() const { return glm::vec4( position.x, position.y, position.x + size.x, position.y + size.y ); }

	inline const int get_width() const { return size.x; }
	inline const int get_height() const { return size.y; }
};