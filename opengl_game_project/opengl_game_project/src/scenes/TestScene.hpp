#pragma once

#include <memory>
#include <vector>

#include "../gl/objects/Program.hpp"
#include "../systems/PlayerMovement.hpp"
#include "../systems/Renderer.hpp"
#include "../systems/System.hpp"
#include "../Font.hpp"
#include "../Text.hpp"
#include "Scene.hpp"

class TestScene : public Scene
{
public:
	TestScene();
	~TestScene() = default;
	void render() override;

private:
	std::vector<std::unique_ptr<System>> m_systems;
	Font m_font;
	Text m_text;
};
