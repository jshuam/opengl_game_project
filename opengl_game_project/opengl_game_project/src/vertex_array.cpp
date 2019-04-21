#include "Vertex_Array.h"

#include "Renderer.h"

Vertex_Array::Vertex_Array()
{
	glGenVertexArrays( 1, &renderer_id );
}

Vertex_Array::~Vertex_Array()
{
	glDeleteVertexArrays( 1, &renderer_id );
}

void Vertex_Array::add_buffer( const Vertex_Buffer& vb )
{
	bind();
	vb.bind();
	vbos.push_back( vb );
	vb.attrib_pointer( vbos.size() - 1 );
}

void Vertex_Array::bind() const
{
	glBindVertexArray( renderer_id );

	for( int i = 0; i < vbos.size(); i++ )
	{
		glEnableVertexAttribArray( i );
	}
}

void Vertex_Array::unbind() const
{
	glBindVertexArray( 0 );
}
