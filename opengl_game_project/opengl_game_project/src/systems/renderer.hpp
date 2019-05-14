#pragma 

#include "system.hpp"
#include "..\gl\objects\Program.hpp"

class Renderer : public System
{
private:
	std::unique_ptr<Program> program;

public:
	Renderer() = default;

	virtual void update() const override;
	void add_program( std::unique_ptr<Program> program );

};