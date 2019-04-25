#include "Renderer.h"

Renderer::Renderer()
{
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
}

void Renderer::draw( unsigned int vertex_count ) const
{
	glDrawElements( GL_TRIANGLES, vertex_count, GL_UNSIGNED_INT, nullptr );
}
