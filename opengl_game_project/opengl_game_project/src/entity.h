#pragma once

#include "VertexArray.h"
#include "IndexBuffer.h"

class Entity
{
private:
	VertexArray vao;
	IndexBuffer ibo;

public:
	Entity( const VertexArray& va, const IndexBuffer& ibo );

	void bind() const;
	void unbind() const;

	inline int get_vertex_count() const { return ibo.get_count(); }
};