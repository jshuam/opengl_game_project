#pragma once

#include "../components/IComponent.hpp"
#include "../components/BaseComponent.hpp"

#include <memory>
#include <map>
#include <initguid.h>
#include <guiddef.h>
#include <functional>
#include "../utils.hpp"

class Entity
{
private:
	GUID m_entityId;
	std::map<unsigned int, std::unique_ptr<IComponent>> components;

public:
	Entity();

	const GUID& get_id();

	template<typename T>
	void add_component( std::unique_ptr<BaseComponent<T>> component )
	{
		components.emplace( BaseComponent<T>::m_component_id, std::move( component ) );
	}

	template<typename T>
	T& get_component()
	{
		return static_cast<T&>( *components[T::component_id] );
	}
};