#include "Renderer.h"

renderer::renderer()
{
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
}

void renderer::clear() const
{
	glClear( GL_COLOR_BUFFER_BIT );
}

void renderer::draw() const
{
	glDrawElements( GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr );
}
