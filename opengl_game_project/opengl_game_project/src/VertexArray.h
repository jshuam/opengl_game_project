#pragma once

#include "VertexBuffer.h"

#include <vector>

class VertexArray
{
private:
	unsigned int renderer_id;
	std::vector<VertexBuffer> vbos;

public:
	VertexArray();
	~VertexArray();

	void add_buffer( VertexBuffer vb );

	void bind() const;
	void unbind() const;
};

