#include "IComponent.hpp"

unsigned int IComponent::m_baseComponentId = 0;

unsigned int IComponent::createComponentId()
{
    return m_baseComponentId++;
}
