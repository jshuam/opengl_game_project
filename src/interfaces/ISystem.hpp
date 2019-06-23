#pragma once

#include <uuid/uuid.h>
#include <vector>

class ISystem
{
public:
    virtual ~ISystem() = default;
    virtual void update() const = 0;

    void addEntity(const uuid_t& entity_id);

protected:
    std::vector<uuid_t> m_entities;
};
