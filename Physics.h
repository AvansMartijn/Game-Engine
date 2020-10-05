#pragma once

#include "GameObject.h"


class Physics
{
private:
	std::vector<GameObject> _gameObjects;
public:
	void changeVelocity(GameObject object, Vec2 velocity);
	void changePosition(GameObject object, Vec2 position);
};

