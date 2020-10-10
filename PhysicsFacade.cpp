#include "PhysicsFacade.h"

void PhysicsFacade::setPosition(shared_ptr<GameObject> gameObject, Vec2 position)
{
	gameObject->physicalBody.body.position = position;
}

void PhysicsFacade::updatePosition(shared_ptr<GameObject> gameObject)
{
	gameObject->physicalBody.shape.min += gameObject->physicalBody.body.velocity;
	gameObject->physicalBody.shape.max += gameObject->physicalBody.body.velocity;
	gameObject->physicalBody.body.position += gameObject->physicalBody.body.velocity;

}

void PhysicsFacade::resolveCollision(shared_ptr<GameObject> objectA, shared_ptr<GameObject> objectB)
{
	Collision col;
	col.resolveCollision(objectA, objectB);
}

vector<shared_ptr<GameObject>> PhysicsFacade::getCollisions(shared_ptr<GameObject> objectA, std::vector<shared_ptr<GameObject>> objectList)
{
	Collision col;
	return col.getCollisions(objectA, objectList);
}
