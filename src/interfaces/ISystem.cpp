#include "ISystem.hpp"

void ISystem::addEntity(const UUID& entityId)
{
    m_entities.push_back(entityId);
}
