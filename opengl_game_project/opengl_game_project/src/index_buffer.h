#pragma once

class Index_Buffer
{
private:
	unsigned int renderer_id;
	unsigned int count;

public:
	Index_Buffer( const unsigned int* data, unsigned int count );
	~Index_Buffer();

	void bind() const;
	void unbind() const;
	void modify_buffer( unsigned int data_size, const void* data ) const;

	inline unsigned int get_count() const { return count; }
};

