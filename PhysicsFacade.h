#pragma once
#include "Physics.h"
#include "Collision.h"
class PhysicsFacade
{
private:
	Physics _physics;
public:
	void setPosition(shared_ptr<GameObject> gameObject, Vec2 position);
	void updatePosition(shared_ptr<GameObject> gameObject);
	vector<shared_ptr<GameObject>> getCollisions(shared_ptr<GameObject> objectA, std::vector<shared_ptr<GameObject>> objectList);
};

