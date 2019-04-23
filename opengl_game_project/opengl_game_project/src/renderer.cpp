#include "Renderer.h"

Renderer::Renderer()
{
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
}

void Renderer::draw( const Entity& entity ) const
{
	glDrawElements( GL_TRIANGLES, entity.get_vertex_count(), GL_UNSIGNED_INT, nullptr );
}
