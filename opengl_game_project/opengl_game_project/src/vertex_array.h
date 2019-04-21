#pragma once

#include "Vertex_Buffer.h"

#include <vector>

class Vertex_Array
{
private:
	unsigned int renderer_id;
	std::vector<Vertex_Buffer> vbos;

public:
	Vertex_Array();
	~Vertex_Array();

	void add_buffer( const Vertex_Buffer& vb );

	void bind() const;
	void unbind() const;
};

