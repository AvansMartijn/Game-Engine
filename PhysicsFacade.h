#pragma once
#include "Physics.h"
class PhysicsFacade
{
private:
	Physics _physics;
public:
	void setPosition(shared_ptr<GameObject> gameObject, Vec2 position);
	void updatePosition(shared_ptr<GameObject> gameObject);
};

