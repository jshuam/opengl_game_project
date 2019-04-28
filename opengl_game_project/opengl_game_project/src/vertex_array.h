#pragma once

#include "vertex_buffer.h"

#include <vector>

class VertexArray
{
private:
	unsigned int renderer_id;
	std::vector<VertexBuffer> vbos;

public:
	VertexArray();

	void add_buffer( VertexBuffer vb );

	void bind() const;
	void unbind() const;

	inline const auto& get_vertex_buffers() { return vbos; }
	inline const auto& get_id() const { return renderer_id; }
};

