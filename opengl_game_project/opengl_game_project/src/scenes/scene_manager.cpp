#include "scene_manager.hpp"

void SceneManager::add_scene( Scene* scene )
{
	scenes.emplace_back( scene );
}

void SceneManager::set_active_scene( unsigned int scene_id )
{
	active_scene = scenes[scene_id];
}

void SceneManager::render_scene()
{
	active_scene->render();
}

std::vector<Scene*> SceneManager::scenes;
Scene* SceneManager::active_scene;