#pragma once

#include "Renderer.h"

#include <string>
 
class Texture
{
private:
	static constexpr const int desired_channels = 4;

	unsigned int renderer_id;
	int width, height, bytes_per_pixel;
	std::string file_path;

public:
	Texture() = default;
	Texture( const std::string& file_path );

	void bind( unsigned int slot = 0 ) const;
	void unbind() const;

	inline int get_width() const { return width; }
	inline int get_height() const { return height; }
	inline auto& const get_id() const { return renderer_id; }
};