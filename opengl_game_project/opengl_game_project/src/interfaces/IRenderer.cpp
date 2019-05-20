#include "IRenderer.hpp"


void IRenderer::addProgram(std::unique_ptr<Program> program)
{
	this->m_program = std::move(program);
}
