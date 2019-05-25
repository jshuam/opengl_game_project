#include <stb_image/stb_image.h>

#include "Texture.hpp"

Texture::Texture(const std::string& m_filePath, unsigned int slot)
	:
	m_slot(slot),
	m_width(0),
	m_height(0),
	m_bytesPerPixel(0),
	m_filePath(m_filePath)
{
	stbi_set_flip_vertically_on_load(1);
	unsigned char* localBuffer = stbi_load(m_filePath.c_str(), &m_width, &m_height, &m_bytesPerPixel, DESIRED_CHANNELS);

	glGenTextures(1, &m_glObjectId);
	glBindTexture(GL_TEXTURE_2D, m_glObjectId);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, localBuffer);

	if(localBuffer) stbi_image_free(localBuffer);
}

void Texture::bind() const
{
	glActiveTexture(GL_TEXTURE0 + m_slot);
	glBindTexture(GL_TEXTURE_2D, m_glObjectId);
}

void Texture::unbind() const
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

bool Texture::operator==(const Texture& other) const
{
	return m_glObjectId == other.m_glObjectId;
}
