#pragma once

#include "../gl_drawable.hpp"

#include <string>

class Texture : public GLDrawable
{
private:
	static constexpr const int desired_channels = 4;

	unsigned int slot = 0;
	int width, height, bytes_per_pixel;
	std::string file_path;

public:
	Texture() = default;
	Texture( const std::string& file_path );

	virtual void bind() const override;
	virtual void unbind() const override;

	inline int get_width() const { return width; }
	inline int get_height() const { return height; }

	inline void set_slot( unsigned int slot ) { this->slot = slot; }
};