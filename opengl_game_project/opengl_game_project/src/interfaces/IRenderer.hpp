#pragma once

#include "..\gl\objects\Program.hpp"

class IRenderer
{
public:
	void addProgram(std::unique_ptr<Program> program);

protected:
	std::unique_ptr<Program> m_program;
};
