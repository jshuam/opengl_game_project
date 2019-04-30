#pragma 

#include "system.h"
#include "../components/drawable.h"

class Renderer : public System
{
private:
	Drawable* drawable;

public:
	virtual void update() override;
};