#include "VertexBuffer.hpp"

VertexBuffer::VertexBuffer(unsigned int dataSize, const void* data, int size, unsigned int type, bool normalized, unsigned int drawFlag)
	:
	m_size(size),
	m_type(type),
	m_normalized(normalized)
{
	glGenBuffers(1, &m_glObjectId);
	glBindBuffer(GL_ARRAY_BUFFER, m_glObjectId);
	glBufferData(GL_ARRAY_BUFFER, dataSize, data, drawFlag);
}

void VertexBuffer::bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, m_glObjectId);
}

void VertexBuffer::unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VertexBuffer::attribPointer(unsigned int index) const
{
	glVertexAttribPointer(index, m_size, m_type, m_normalized, 0, 0);
}

void VertexBuffer::modifyBuffer(unsigned int dataSize, const void* data) const
{
	bind();
	glBufferSubData(GL_ARRAY_BUFFER, 0, dataSize, data);
}
