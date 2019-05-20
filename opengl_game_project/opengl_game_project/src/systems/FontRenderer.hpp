#pragma once

#include "System.hpp"

class FontRenderer : public ISystem
{
public:
	FontRenderer();

	virtual void update() const override;
	void addProgram(std::unique_ptr<Program> program);

protected:
	std::unique_ptr<Program> m_program;
};
