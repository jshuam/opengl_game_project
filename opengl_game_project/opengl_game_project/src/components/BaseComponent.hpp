#pragma once

#include "IComponent.hpp"

template<typename T>
class BaseComponent : public IComponent
{
public:
	virtual ~BaseComponent() = default;
	inline const unsigned int getComponentId() { return m_componentId; }

private:
	static const unsigned int m_componentId;
};

template<typename T>
const unsigned int BaseComponent<T>::m_componentId = IComponent::createComponentId();
