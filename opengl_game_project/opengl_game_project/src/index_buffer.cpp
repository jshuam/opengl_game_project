#include "Index_Buffer.h"

#include "Renderer.h"

Index_Buffer::Index_Buffer( const unsigned int* data, unsigned int count )
	: count( count )
{
	glGenBuffers( 1, &renderer_id );
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, renderer_id );
	glBufferData( GL_ELEMENT_ARRAY_BUFFER, sizeof( unsigned int ) * count, data, GL_STATIC_DRAW );
}

Index_Buffer::~Index_Buffer()
{
	glDeleteBuffers( 1, &renderer_id );
}

void Index_Buffer::bind() const
{
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, renderer_id );
}

void Index_Buffer::unbind() const
{
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, 0 );
}

void Index_Buffer::modify_buffer( unsigned int data_size, const void* data ) const
{
	bind();
	glBufferSubData( GL_ELEMENT_ARRAY_BUFFER, 0, data_size, data );
}
