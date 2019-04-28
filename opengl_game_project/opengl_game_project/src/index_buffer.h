#pragma once

class IndexBuffer
{
private:
	unsigned int renderer_id;
	unsigned int count;

public:
	IndexBuffer( const unsigned int* data, unsigned int count );
	//~IndexBuffer();

	void bind() const;
	void unbind() const;
	void modify_buffer( unsigned int data_size, const void* data ) const;

	inline unsigned int get_count() const { return count; }
	inline const auto& get_id() const { return renderer_id; }
};

