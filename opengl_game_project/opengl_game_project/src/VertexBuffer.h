#pragma once

class VertexBuffer
{
private:
	unsigned int renderer_id;
	int size;
	unsigned int type;
	bool normalized;

public:
	VertexBuffer( unsigned int data_size, const void* data, int size, unsigned int type, bool normalized, unsigned int draw_flag );

	void bind() const;
	void unbind() const;

	void attrib_pointer( unsigned int index ) const;
	void modify_buffer( unsigned int data_size, const void* data ) const;

	inline const unsigned int* get_id() const { return &renderer_id; }
};

