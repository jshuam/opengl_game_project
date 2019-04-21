#pragma once

#include "Vertex_Array.h"
#include "Index_Buffer.h"

class Entity
{
private:
	Vertex_Array vao;
	Index_Buffer ibo;

public:
	Entity( const Vertex_Array& va, const Index_Buffer& ibo );

	void bind() const;
	void unbind() const;
};