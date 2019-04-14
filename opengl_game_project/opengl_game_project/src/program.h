#pragma once

#include "shader.h"

#include <string>
#include <vector>
#include <unordered_map>

class program
{
private:
	unsigned int renderer_id;
	std::vector<shader> shaders;
	std::unordered_map<std::string, unsigned int> uniform_loc_cache;

public:
	program();
	~program();

	void bind() const;
	void unbind() const;
	void attach_shader( shader shader );
	void compile() const;

	void set_uniform_4f( const std::string& name, float v0, float v1, float v2, float v3 );

private:
	void check_compile_status( unsigned int param ) const;
	unsigned int get_uniform_location( const std::string& name );
};