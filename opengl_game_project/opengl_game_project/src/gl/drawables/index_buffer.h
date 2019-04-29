#pragma once

#include "../gl_drawable.h"

class IndexBuffer : public GLDrawable
{
private:
	unsigned int count;

public:
	IndexBuffer( const unsigned int* data, unsigned int count );
	//~IndexBuffer();

	void bind() const;
	void unbind() const;
	void modify_buffer( unsigned int data_size, const void* data ) const;

	inline unsigned int get_count() const { return count; }
};

