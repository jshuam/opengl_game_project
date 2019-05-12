#pragma once

#include "../components/BaseComponent.hpp"
#include "../components/IComponent.hpp"

class Entity
{
public:
	Entity();
	const GUID& getEntityId();

	template<typename T>
	void addComponent(std::unique_ptr<BaseComponent<T>> component)
	{
		m_components.emplace(BaseComponent<T>::m_componentId, std::move(component));
	}

	template<typename T>
	T& getComponent()
	{
		return static_cast<T&>(*m_components[T::component_id]);
	}

private:
	GUID m_entityId;
	std::map<unsigned int, std::unique_ptr<IComponent>> m_components;
};