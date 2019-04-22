#include "Text.h"

Text::Text( const char* text, Font* font, glm::vec2 position, float scale, glm::vec3 color )
	:
	text( text ),
	font( font ),
	position( position ),
	scale( scale ),
	color( color ),
	size( font->get_text_size( text, scale ) )
{}

void Text::render() const
{
	font->render_text( text, position, scale, color );
}
