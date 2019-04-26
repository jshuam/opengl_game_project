#pragma once

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Texture.h"

class Entity
{
private:
	VertexArray vao;
	IndexBuffer ibo;
	Texture texture;

public:
	Entity( VertexArray vao, IndexBuffer ibo, Texture texture );
	~Entity();

	void bind() const;
	void unbind() const;

	inline int get_vertex_count() const { return ibo.get_count(); }
};