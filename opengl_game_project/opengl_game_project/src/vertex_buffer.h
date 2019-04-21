#pragma once

class Vertex_Buffer
{
private:
	unsigned int renderer_id;
	int size;
	unsigned int type;
	bool normalized;

public:
	Vertex_Buffer( unsigned int data_size, const void* data, int size, unsigned int type, bool normalized, unsigned int draw_flag );
	~Vertex_Buffer();

	void bind() const;
	void unbind() const;

	void attrib_pointer( unsigned int index ) const;
	void modify_buffer( unsigned int data_size, const void* data );
};

