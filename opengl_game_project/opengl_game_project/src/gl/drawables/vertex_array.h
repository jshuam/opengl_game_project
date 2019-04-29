#pragma once

#include "../gl_drawable.h"
#include "vertex_buffer.h"

#include <vector>

class VertexArray : public GLDrawable
{
private:
	std::vector<VertexBuffer> vbos;

public:
	VertexArray();

	void add_buffer( VertexBuffer vb );

	virtual void bind() const override;
	virtual void unbind() const override;

	inline const auto& get_vertex_buffers() { return vbos; }
};

