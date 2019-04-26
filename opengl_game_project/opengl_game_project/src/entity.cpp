#include "Entity.h"

#include <GL/glew.h>

Entity::Entity( VertexArray vao, IndexBuffer ibo, Texture texture )
	:
	vao( vao ),
	ibo( ibo ),
	texture( texture )
{}

Entity::~Entity()
{
	for( auto& vbo : vao.get_vertex_buffers() )
	{
		glDeleteBuffers( 1, &vbo.get_id() );
	}
	glDeleteVertexArrays( 1, &vao.get_id() );
	glDeleteBuffers( 1, &ibo.get_id() );
	glDeleteTextures( 1, &texture.get_id() );
}

void Entity::bind() const
{
	texture.bind();
	vao.bind();
	ibo.bind();
}

void Entity::unbind() const
{
	vao.unbind();
	ibo.unbind();
}
