#pragma once

#include <string>

class shader
{
private:
	unsigned int renderer_id;

public:
	shader( unsigned int type, const std::string& filename );

	void attach( unsigned int program ) const;
	void detach( unsigned int program ) const;

private:
	const std::string load_source( const std::string& filename );
	unsigned int compile_source( unsigned int type, const std::string& shader_src );
};
