#include "IndexBuffer.h"

#include "Renderer.h"

IndexBuffer::IndexBuffer( const unsigned int* data, unsigned int count )
	: count( count )
{
	glGenBuffers( 1, &renderer_id );
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, renderer_id );
	glBufferData( GL_ELEMENT_ARRAY_BUFFER, sizeof( unsigned int ) * count, data, GL_STATIC_DRAW );
}

//IndexBuffer::~IndexBuffer()
//{
//	glDeleteBuffers( 1, &renderer_id );
//}

void IndexBuffer::bind() const
{
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, renderer_id );
}

void IndexBuffer::unbind() const
{
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, 0 );
}

void IndexBuffer::modify_buffer( unsigned int data_size, const void* data ) const
{
	bind();
	glBufferSubData( GL_ELEMENT_ARRAY_BUFFER, 0, data_size, data );
}
