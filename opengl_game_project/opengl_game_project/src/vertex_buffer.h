#pragma once

#include "vertex_buffer_layout.h"

class vertex_buffer
{
private:
	unsigned int renderer_id;

public:
	vertex_buffer_layout layout;

public:
	vertex_buffer( const void* data, unsigned int size );
	~vertex_buffer();

	void bind() const;
	void unbind() const;
};

