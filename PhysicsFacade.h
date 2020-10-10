#pragma once
#include "Physics.h"
#include "Collision.h"
class PhysicsFacade
{
private:
	Physics _physics;
	Collision _collision;
public:
	void setPosition(shared_ptr<GameObject> gameObject, Vec2 position);
	void updatePosition(shared_ptr<GameObject> gameObject);
	void resolveCollision(shared_ptr<GameObject> objectA, shared_ptr<GameObject> objectB);
	void addGravityForce(shared_ptr<GameObject> gameObject);
	vector<shared_ptr<GameObject>> getCollisions(shared_ptr<GameObject> objectA, std::vector<shared_ptr<GameObject>> objectList);
};

