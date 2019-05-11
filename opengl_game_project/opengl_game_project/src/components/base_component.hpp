#pragma once

class BaseComponent
{
private:
	static unsigned int base_component_id;

public:
	static unsigned int create_component_id();
};
