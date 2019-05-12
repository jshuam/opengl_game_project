#pragma once

#include "../GLObject.hpp"

#include <string>

class Shader : public GLObject
{
public:
	Shader( unsigned int type, const std::string& filename );

	void attach( unsigned int program ) const;
	void detach( unsigned int program ) const;

private:
	const std::string load_source( const std::string& filename );
	unsigned int compile_source( unsigned int type, const std::string& shader_src );
};

