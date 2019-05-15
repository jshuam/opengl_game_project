#include <iostream>

#include "VertexArray.hpp"

VertexArray::VertexArray()
{
	glGenVertexArrays(1, &m_glObjectId);
	glBindVertexArray(m_glObjectId);
}

void VertexArray::addBuffer(VertexBuffer vertexBuffer)
{
	bind();
	vertexBuffer.bind();
	vbos.push_back(std::move(vertexBuffer));
	vertexBuffer.attribPointer(vbos.size() - 1);
	glEnableVertexAttribArray(vbos.size() - 1);
}

void VertexArray::bind() const
{
	glBindVertexArray(m_glObjectId);
}

void VertexArray::unbind() const
{
	glBindVertexArray(0);
}
