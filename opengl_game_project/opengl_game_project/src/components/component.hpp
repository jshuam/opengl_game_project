#pragma once
#include "base_component.hpp"

template<typename T>
class Component : public BaseComponent
{
public:
	static const unsigned int component_id;

public:
	virtual ~Component() = default;
};

template<typename T>
const unsigned int Component<T>::component_id = BaseComponent::create_component_id();
