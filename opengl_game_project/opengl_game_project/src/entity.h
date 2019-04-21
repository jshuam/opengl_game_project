#pragma once

#include "Vertex_Array.h"
#include "Index_Buffer.h"

class Entity
{
private:
	Vertex_Array va;
	Index_Buffer index_buffer;

public:
	Entity( const Vertex_Array& va, const Index_Buffer& index_buffer );

	void bind() const;
	void unbind() const;
};