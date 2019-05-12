#include "vertex_array.hpp"

#include <iostream>

VertexArray::VertexArray()
{
	glGenVertexArrays( 1, &gl_id );
	glBindVertexArray( gl_id );
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
	glBindVertexArray( gl_id );
}

void VertexArray::unbind() const
{
	glBindVertexArray( 0 );
}
