#include "Entity.hpp"

Entity::Entity()
    : m_entityId()
{
    uuid_generate_time_safe(m_entityId);
}

const uuid_t& Entity::getEntityId()
{
    return m_entityId;
}
