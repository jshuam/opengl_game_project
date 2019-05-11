#pragma once

#include "../components/base_component.hpp"
#include "../components/component.hpp"

#include <memory>
#include <map>
#include <initguid.h>
#include <guiddef.h>
#include <functional>
#include "../utils.hpp"

class Entity
{
private:
	GUID id;
	std::map<unsigned int, std::unique_ptr<BaseComponent>> components;

public:
	Entity();

	const GUID& get_id();

	template<typename T>
	void add_component( std::unique_ptr<Component<T>> component )
	{
		components.insert( { component->component_id, std::move( component ) } );
	}

	template<typename T>
	std::unique_ptr <Component<T>>& get_component( unsigned int component_id )
	{
		return components[component_id];
	}
};