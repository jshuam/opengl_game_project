#pragma once

#include <vector>
#include <initguid.h>
#include <guiddef.h>

class System
{
protected:
	std::vector<GUID> entities;

public:
	virtual ~System() = default;

	virtual void add_entity( const GUID& entity_id ) = 0;
	virtual void update() const = 0;
};
