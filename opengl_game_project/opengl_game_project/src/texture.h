#pragma once

#include "renderer.h"

#include <string>
 
class texture
{
private:
	static constexpr const int desired_channels = 4;

	unsigned int renderer_id;
	unsigned char* local_buffer;
	int width, height, bytes_per_pixel;
	std::string file_path;

public:
	texture( const std::string& file_path );
	~texture();

	void bind( unsigned int slot = 0 ) const;
	void unbind() const;

	inline int get_width() const { return width; }
	inline int get_height() const { return height; }
};