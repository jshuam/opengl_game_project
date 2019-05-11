#pragma once

#include "../gl_drawable.hpp"

class IndexBuffer : public GLDrawable
{
private:
	unsigned int count;

public:
	IndexBuffer( const unsigned int* data, unsigned int count );
	//~IndexBuffer();

	virtual void bind() const override;
	virtual void unbind() const override;
	void modify_buffer( unsigned int data_size, const void* data ) const;

	inline unsigned int get_count() const { return count; }
};

