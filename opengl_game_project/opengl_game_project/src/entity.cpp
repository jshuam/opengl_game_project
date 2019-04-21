#include "Entity.h"

Entity::Entity( const Vertex_Array& va, const Index_Buffer& index_buffer )
	:
	va( va ),
	index_buffer( index_buffer )
{}

void Entity::bind() const
{
	va.bind();
	index_buffer.bind();
}

void Entity::unbind() const
{
	va.unbind();
	index_buffer.unbind();
}
