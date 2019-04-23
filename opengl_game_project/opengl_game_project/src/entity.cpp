#include "Entity.h"

Entity::Entity( const VertexArray& vao, const IndexBuffer& ibo )
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
