#pragma once

#include <map>
#include <memory>
#include <uuid/uuid.h>

#include "../components/BaseComponent.hpp"
#include "../interfaces/IComponent.hpp"

class Entity
{
public:
    Entity();
    const uuid_t& getEntityId();

    template <typename T>
    void addComponent(std::unique_ptr<BaseComponent<T>> component)
    {
        m_components.emplace(BaseComponent<T>::getComponentId(), std::move(component));
    }

    template <typename T>
    T& getComponent()
    {
        return static_cast<T&>(*m_components[T::getComponentId()]);
    }

private:
    uuid_t m_entityId;
    std::map<unsigned int, std::unique_ptr<IComponent>> m_components;
};
