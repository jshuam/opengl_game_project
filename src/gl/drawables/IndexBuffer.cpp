#include "IndexBuffer.hpp"

IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count)
    : m_count(count)
{
    glGenBuffers(1, &m_glObjectId);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_glObjectId);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * m_count, data, GL_STATIC_DRAW);
}

void IndexBuffer::bind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_glObjectId);
}

void IndexBuffer::unbind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void IndexBuffer::modifyBuffer(unsigned int dataSize, const void* data) const
{
    bind();
    glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, dataSize, data);
}
