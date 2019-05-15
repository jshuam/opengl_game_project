#pragma once

#include "../GLDrawable.hpp"

class IndexBuffer : public GLDrawable
{
public:
	IndexBuffer(const unsigned int* data, unsigned int count);

	virtual void bind() const override;
	virtual void unbind() const override;
	void modifyBuffer(unsigned int dataSize, const void* data) const;

	inline unsigned int getCount() const { return m_count; }

private:
	unsigned int m_count;
};
