#include "Text.h"

Text::Text( const char* text, glm::vec2 position, float scale, glm::vec3 color, Font* font )
	:
	text( text ),
	position( position ),
	scale( scale ),
	color( color ),
	font( font )
{
	size = font->get_text_size( text, scale );
}

void Text::render() const
{
	font->render_text( text, position, scale, color );
}
