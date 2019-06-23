#include "ISystem.hpp"

void ISystem::addEntity(const uuid_t& entityId)
{
    m_entities.push_back(entityId);
}
