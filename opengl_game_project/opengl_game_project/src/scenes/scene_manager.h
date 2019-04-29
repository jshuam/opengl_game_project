#pragma once

#include "scene.h"

#include <vector>

class SceneManager
{
private:
	static std::vector<Scene*> scenes;
	static Scene* active_scene;

public:
	static void add_scene( scene* scene );
	static void set_active_scene( unsigned int scene_id );
	static void render_scene();
};