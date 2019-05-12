#pragma once

#include <string>

#include "../GLDrawable.hpp"

class Texture : public GLDrawable
{
public:
	Texture() = default;
	Texture(const std::string& filePath);

	virtual void bind() const override;
	virtual void unbind() const override;

	inline int getWidth() const { return m_width; }
	inline int getHeight() const { return m_height; }

	inline void setSlot(unsigned int slot) { m_slot = slot; }

private:
	static constexpr const int DESIRED_CHANNELS = 4;

	unsigned int m_slot = 0;
	int m_width, m_height, m_bytesPerPixel;
	std::string m_filePath;
};