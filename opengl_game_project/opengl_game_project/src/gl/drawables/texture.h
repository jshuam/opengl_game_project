#pragma once

#include "../gl_drawable.h"

#include <string>
 
class Texture : public GLDrawable
{
private:
	static constexpr const int desired_channels = 4;

	int width, height, bytes_per_pixel;
	std::string file_path;

public:
	Texture() = default;
	Texture( const std::string& file_path );

	void bind( unsigned int slot = 0 ) const;
	void unbind() const;

	inline int get_width() const { return width; }
	inline int get_height() const { return height; }
};