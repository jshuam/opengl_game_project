#include "Texture.h"

#include <stb_image/stb_image.h>

Texture::Texture( const std::string& file_path )
	:
	renderer_id( 0 ),
	local_buffer( nullptr ),
	width( 0 ),
	height( 0 ),
	bytes_per_pixel( 0 ),
	file_path( file_path )
{
	stbi_set_flip_vertically_on_load( 1 );
	local_buffer = stbi_load( file_path.c_str(), &width, &height, &bytes_per_pixel, desired_channels );

	glGenTextures( 1, &renderer_id );
	glBindTexture( GL_TEXTURE_2D, renderer_id );

	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );

	glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, local_buffer );

	if( local_buffer ) stbi_image_free( local_buffer );
}

Texture::~Texture()
{
	glDeleteTextures( 1, &renderer_id );
}

void Texture::bind( unsigned int slot ) const
{
	glActiveTexture( GL_TEXTURE0 + slot );
	glBindTexture( GL_TEXTURE_2D, renderer_id );
}

void Texture::unbind() const
{
	glBindTexture( GL_TEXTURE_2D, 0 );
}
