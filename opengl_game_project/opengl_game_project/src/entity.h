#pragma once

#include "vertex_array.h"
#include "index_buffer.h"

class entity
{
private:
	vertex_array va;
	index_buffer ib;

public:
	entity( const vertex_array& va, const index_buffer& ib );

	void bind() const;
	void unbind() const;
};