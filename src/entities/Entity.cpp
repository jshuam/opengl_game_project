#include "Entity.hpp"

Entity::Entity()
    : m_entityId()
{
    m_entityId.generateInplace();
}

const UUID& Entity::getEntityId()
{
    return m_entityId;
}
