#include "vertex_array.hpp"

#include <iostream>

VertexArray::VertexArray()
{
	glGenVertexArrays( 1, &m_glObjectId );
	glBindVertexArray( m_glObjectId );
}

void VertexArray::add_buffer( VertexBuffer vb )
{
	bind();
	vb.bind();
	vbos.push_back( std::move( vb ) );
	vb.attrib_pointer( vbos.size() - 1 );
	glEnableVertexAttribArray( vbos.size() - 1 );
}

void VertexArray::bind() const
{
	glBindVertexArray( m_glObjectId );
}

void VertexArray::unbind() const
{
	glBindVertexArray( 0 );
}
