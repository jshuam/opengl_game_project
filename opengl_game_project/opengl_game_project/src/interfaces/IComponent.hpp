#pragma once

class IComponent
{
public:
	virtual ~IComponent() = default;
	static unsigned int createComponentId();

private:
	static unsigned int m_baseComponentId;
};
