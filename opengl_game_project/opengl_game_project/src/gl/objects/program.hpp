#pragma once

#include <glm/glm.hpp>

#include <string>
#include <unordered_map>
#include <vector>

#include "../GLObject.hpp"
#include "Shader.hpp"

class Program : public GLObject
{

public:
	Program();
	~Program();

	void bind() const;
	void unbind() const;

	void attachShader(Shader shader);
	void compile() const;

	void setUniform1i(const std::string& name, int v0);
	void setUniform3f(const std::string& name, float v0, float v1, float v2);
	void setUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
	void setUniformVec4f(const std::string& name, const glm::vec4& vec);
	void setUniformMat4f(const std::string& name, glm::mat4& matrix);

private:
	void checkCompileStatus(unsigned int param) const;
	int getUniformLocation(const std::string& name);

private:
	std::vector<Shader> m_shaders;
	std::unordered_map<std::string, int> m_uniformLocCache;
};
