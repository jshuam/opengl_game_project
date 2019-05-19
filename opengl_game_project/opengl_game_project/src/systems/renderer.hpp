#pragma once

#include "..\gl\objects\Program.hpp"
#include "System.hpp"

class Renderer : public System
{
public:
	Renderer() = default;

	virtual void update() const override;
	void addProgram(std::unique_ptr<Program> program);

protected:
	std::unique_ptr<Program> m_program;

};
