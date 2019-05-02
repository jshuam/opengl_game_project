#pragma 

#include "system.h"
#include "../components/drawable.h"

class Renderer : public System
{
private:
	std::shared_ptr<Drawable> drawable;

public:
	Renderer( std::shared_ptr<Drawable> drawable );
	virtual void update() override;
};