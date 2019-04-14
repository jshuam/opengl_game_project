#include "index_buffer.h"

#include "renderer.h"

index_buffer::index_buffer( const unsigned int* data, unsigned int count )
	: count( count )
{
	glGenBuffers( 1, &renderer_id );
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, renderer_id );
	glBufferData( GL_ELEMENT_ARRAY_BUFFER, sizeof( unsigned int ) * count, data, GL_STATIC_DRAW );
}

index_buffer::~index_buffer()
{
	glDeleteBuffers( 1, &renderer_id );
}

void index_buffer::bind() const
{
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, renderer_id );
}

void index_buffer::unbind() const
{
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, 0 );
}
