#include "SceneManager.hpp"

std::vector<Scene*> SceneManager::m_scenes;
Scene* SceneManager::m_activeScene;

void SceneManager::addScene(Scene* scene)
{
    m_scenes.emplace_back(scene);
}

void SceneManager::setActiveScene(unsigned int scene_id)
{
    m_activeScene = m_scenes[scene_id];
}

void SceneManager::processScene()
{
    m_activeScene->process();
}
