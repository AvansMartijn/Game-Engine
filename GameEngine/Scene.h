#pragma once
#include <vector>
#include <memory>
#include "GameObject.h"

class Scene
{
private:
	Scene();
	static Scene instance;
public:
	static Scene& getInstance() { return instance; }
	Scene(const Scene&) = delete;
	Scene(Scene&&) = delete;
	Scene& operator=(const Scene&) = delete;
	Scene& operator=(Scene&&) = delete;

	vector<shared_ptr<GameObject>> gameObjects;
	shared_ptr<GameObject> player;
};

