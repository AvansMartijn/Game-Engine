#include "PhysicsFacade.h"

void PhysicsFacade::setPosition(shared_ptr<GameObject> gameObject, const Vec2& position)
{
	_physics.setPosition(gameObject, position);
}

void PhysicsFacade::updatePosition(shared_ptr<GameObject> gameObject)
{
	_physics.updatePosition(gameObject);
}

void PhysicsFacade::resolveCollision(shared_ptr<GameObject> objectA, shared_ptr<GameObject> objectB)
{
	_collision.resolveCollision(objectA, objectB);
}

void PhysicsFacade::addGravityForce(shared_ptr<GameObject> gameObject)
{
	_physics.addGravityForce(gameObject);
}

vector<shared_ptr<GameObject>> PhysicsFacade::getCollisions(shared_ptr<GameObject> objectA, std::vector<shared_ptr<GameObject>> objectList)
{
	return _collision.getCollisions(objectA, objectList);
}
