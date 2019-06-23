#pragma once

#include <memory>

#include "../gl/objects/Program.hpp"

class IRenderer
{
public:
    void addProgram(std::unique_ptr<Program> program);
    virtual void render() { throw std::logic_error("Render function not implemented"); };

protected:
    std::unique_ptr<Program> m_program;
};
