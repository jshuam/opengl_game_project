#include "Entity.h"

Entity::Entity( const Vertex_Array& vao, const Index_Buffer& ibo )
	:
	vao( vao ),
	ibo( ibo )
{}

void Entity::bind() const
{
	vao.bind();
	ibo.bind();
}

void Entity::unbind() const
{
	vao.unbind();
	ibo.unbind();
}
