#pragma once

#include "Scene.hpp"

#include <vector>

class SceneManager
{
public:
	static void addScene(Scene* scene);
	static void setActiveScene(unsigned int scene_id);
	static void renderScene();

private:
	static std::vector<Scene*> m_scenes;
	static Scene* m_activeScene;
};
