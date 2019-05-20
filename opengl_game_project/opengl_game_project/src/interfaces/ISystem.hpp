#pragma once

#include <initguid.h>
#include <guiddef.h>
#include <vector>

class ISystem
{
public:
	virtual ~ISystem() = default;
	virtual void update() const = 0;

	void addEntity(const GUID& entity_id);

protected:
	std::vector<GUID> m_entities;
};
