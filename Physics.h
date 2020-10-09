#pragma once

#include "GameObject.h"


class Physics
{
private:
	//std::vector<shared_ptr<GameObject>> _gameObjects;
public:
	void changeVelocity(shared_ptr<GameObject> object, Vec2 velocity);
	void setPosition(shared_ptr<GameObject> object, Vec2 position);
	void updatePosition(shared_ptr<GameObject> object);
};

