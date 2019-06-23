#pragma once

#include "glm/ext/vector_float3.hpp"

#include "BaseComponent.hpp"

class TransformComponent : public BaseComponent<TransformComponent>
{
public:
    TransformComponent(glm::vec3 position = { 0, 0, 0 }, glm::vec3 scale = { 1.0f, 1.0f, 1.0f });
    inline glm::vec3& getPosition() { return m_position; };
    inline glm::vec3& getScale() { return m_scale; };

private:
    glm::vec3 m_position;
    glm::vec3 m_scale;
};
