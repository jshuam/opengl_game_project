#pragma once

#include <memory>
#include <vector>

#include "../interfaces/ISystem.hpp"
#include "Scene.hpp"

class TestScene : public Scene
{
public:
    TestScene();
    ~TestScene() = default;
    void process() override;
};
