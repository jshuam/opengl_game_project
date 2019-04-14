#pragma once

#include <vector>

#include <GL/glew.h>

class vertex_buffer_layout
{
public:
	struct element
	{
		unsigned int type;
		unsigned int count;
		unsigned char normalized;

		static unsigned int get_size( unsigned int type )
		{
			switch( type )
			{
				case GL_FLOAT: return sizeof( GL_FLOAT );
				case GL_UNSIGNED_INT: return sizeof( GL_UNSIGNED_INT );
				case GL_UNSIGNED_BYTE: return sizeof( GL_UNSIGNED_BYTE );
			}

			return 0;
		}
	};

private:
	std::vector<element> elements;
	unsigned int stride;

public:
	vertex_buffer_layout()
		: stride( 0 )
	{}

	template<typename T>
	void push( unsigned int count )
	{
		static_assert( false );
	}

	template<>
	void push<float>( unsigned int count )
	{
		elements.push_back( { GL_FLOAT, count, GL_FALSE } );
		stride += element::get_size( GL_FLOAT ) * count;
	}

	template<>
	void push<unsigned int>( unsigned int count )
	{
		elements.push_back( { GL_UNSIGNED_INT, count, GL_FALSE } );
		stride += element::get_size( GL_UNSIGNED_INT ) * count;
	}

	template<>
	void push<unsigned char>( unsigned int count )
	{
		elements.push_back( { GL_UNSIGNED_BYTE, count, GL_TRUE } );
		stride += element::get_size( GL_UNSIGNED_BYTE ) * count;
	}

	inline const std::vector<element>& get_elements() const { return elements; }
	inline unsigned int get_stride() const { return stride; }
};

