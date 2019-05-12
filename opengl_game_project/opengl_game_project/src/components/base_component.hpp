#pragma once

class BaseComponent
{
private:
	static unsigned int base_component_id;

public:
	virtual ~BaseComponent() = default;
	static unsigned int create_component_id();
};
