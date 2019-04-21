#include "Vertex_Buffer.h"

#include "Renderer.h"

Vertex_Buffer::Vertex_Buffer( unsigned int data_size, const void* data, int size, unsigned int type, bool normalized, unsigned int draw_flag )
	:
	renderer_id( 0 ),
	size( size ),
	type( type ),
	normalized( normalized )
{
	glGenBuffers( 1, &renderer_id );
	glBindBuffer( GL_ARRAY_BUFFER, renderer_id );
	glBufferData( GL_ARRAY_BUFFER, data_size, data, draw_flag );
}

void Vertex_Buffer::bind() const
{
	glBindBuffer( GL_ARRAY_BUFFER, renderer_id );
}

void Vertex_Buffer::unbind() const
{
	glBindBuffer( GL_ARRAY_BUFFER, 0 );
}

void Vertex_Buffer::attrib_pointer( unsigned int index ) const
{
	glVertexAttribPointer( index, size, type, normalized, 0, 0 );
}

void Vertex_Buffer::modify_buffer( unsigned int data_size, const void* data )
{
	bind();
	glBufferSubData( GL_ARRAY_BUFFER, 0, data_size, data );
}
