#include "vertex_array.h"

#include "renderer.h"

vertex_array::vertex_array()
{
	glGenVertexArrays( 1, &renderer_id );
}

vertex_array::~vertex_array()
{
	glDeleteVertexArrays( 1, &renderer_id );
}

void vertex_array::add_buffer( const vertex_buffer& vb, const vertex_buffer_layout& layout )
{
	bind();
	vb.bind();
	const auto& elements = layout.get_elements();
	unsigned int offset = 0;
	for( unsigned int i = 0; i < elements.size(); i++ )
	{
		const auto& element = elements[i];
		glVertexAttribPointer( i, element.count, element.type, element.normalized, layout.get_stride(), (const void*) offset );
		glEnableVertexAttribArray( i );
		offset += element.count * vertex_buffer_layout::element::get_size( element.type );
	}
}

void vertex_array::bind() const
{
	glBindVertexArray( renderer_id );
}

void vertex_array::unbind() const
{
	glBindVertexArray( 0 );
}
