#pragma once

#include "Entity.h"
#include "Shader.h"

#include <glm/glm.hpp>

#include <string>
#include <vector>
#include <unordered_map>

class Program
{
private:
	unsigned int renderer_id;
	std::vector<Entity> entities;
	std::vector<Shader> shaders;
	std::unordered_map<std::string, int> uniform_loc_cache;

public:
	Program();
	~Program();

	void bind() const;
	void unbind() const;

	void add_entity( Entity entity );

	void attach_shader( Shader shader );
	void compile() const;

	void set_uniform_1i( const std::string& name, int v0 );
	void set_uniform_3f( const std::string& name, float v0, float v1, float v2 );
	void set_uniform_4f( const std::string& name, float v0, float v1, float v2, float v3 );
	void set_uniform_mat4f( const std::string& name, glm::mat4& matrix );

private:
	void check_compile_status( unsigned int param ) const;
	int get_uniform_location( const std::string& name );
};