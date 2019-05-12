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
		components.emplace( Component<T>::component_id, std::move( component ) );
	}

	template<typename T>
	T& get_component()
	{
		return static_cast<T&>( *components[T::component_id] );
	}
};