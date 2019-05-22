#include <iostream>

#include "VertexArray.hpp"

VertexArray::VertexArray()
{
	glGenVertexArrays(1, &m_glObjectId);
	glBindVertexArray(m_glObjectId);
}

void VertexArray::addBuffer(unsigned int type, VertexBuffer vertexBuffer)
{
	bind();
	vertexBuffer.bind();
	m_buffers.emplace(type, std::move(vertexBuffer));
	vertexBuffer.attribPointer(m_buffers.size() - 1);
	glEnableVertexAttribArray(m_buffers.size() - 1);
}

void VertexArray::bind() const
{
	glBindVertexArray(m_glObjectId);
}

void VertexArray::unbind() const
{
	glBindVertexArray(0);
}
