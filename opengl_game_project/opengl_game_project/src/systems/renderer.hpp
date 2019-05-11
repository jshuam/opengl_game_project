#pragma 

#include "system.hpp"

class Renderer : public System
{
public:
	Renderer() = default;

	virtual void add_entity( const GUID& entity_id ) override;
	virtual void update() const override;

};