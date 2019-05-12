#pragma once

#include "IComponent.hpp"

template<typename T>
class BaseComponent : public IComponent
{
public:
	virtual ~BaseComponent() = default;
	inline const unsigned int getComponentId() { return m_component_id; }

private:
	static const unsigned int m_component_id;
};

template<typename T>
const unsigned int BaseComponent<T>::m_component_id = IComponent::createComponentId();
