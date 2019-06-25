#pragma once

#include <vector>

#include "../utility/UUID.hpp"

class ISystem
{
public:
    virtual ~ISystem() = default;
    virtual void update() const = 0;

    void addEntity(const UUID& entity_id);

protected:
    std::vector<UUID> m_entities;
};
