#include "Renderer.h"

void renderer::clear() const
{
	glClear( GL_COLOR_BUFFER_BIT );
}

void renderer::draw() const
{
	glDrawElements( GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr );
}
