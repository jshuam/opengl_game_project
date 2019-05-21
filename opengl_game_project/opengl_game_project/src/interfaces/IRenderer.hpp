#pragma once

#include "..\gl\objects\Program.hpp"

class IRenderer
{
public:
	void addProgram(std::unique_ptr<Program> program);
	virtual void render() const { throw std::logic_error("Render function not implemented"); };

protected:
	std::unique_ptr<Program> m_program;
};
