#pragma once

#include <string>

#include "../GLObject.hpp"

class Shader : public GLObject
{
public:
	Shader(unsigned int type, const std::string& filename);

	void attach(unsigned int program) const;
	void detach(unsigned int program) const;

private:
	const std::string loadSource(const std::string& filename);
	unsigned int compileSource(unsigned int type, const std::string& shaderSrc);
};

