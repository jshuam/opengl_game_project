#include "Vertex_Array.h"

#include "Renderer.h"

Vertex_Array::Vertex_Array()
{
	glGenVertexArrays( 1, &renderer_id );
	glBindVertexArray( renderer_id );
}

Vertex_Array::~Vertex_Array()
{
	for( auto& vbo : vbos )
	{
		glDeleteBuffers( 1, vbo.get_id() );
	}

	glDeleteVertexArrays( 1, &renderer_id );
}

void Vertex_Array::add_buffer( Vertex_Buffer vb )
{
	bind();
	vb.bind();
	vbos.push_back( vb );
	vb.attrib_pointer( vbos.size() - 1 );
	glEnableVertexAttribArray( vbos.size() - 1 );
}

void Vertex_Array::bind() const
{
	glBindVertexArray( renderer_id );
}

void Vertex_Array::unbind() const
{
	glBindVertexArray( 0 );
}
