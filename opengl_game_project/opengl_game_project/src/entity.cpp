#include "entity.h"

entity::entity( const vertex_array& va, const index_buffer& ib )
	:
	va( va ),
	ib( ib )
{}

void entity::bind() const
{
	va.bind();
	ib.bind();
}

void entity::unbind() const
{
	va.unbind();
	ib.unbind();
}
