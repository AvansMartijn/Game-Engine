#include "PhysicsFacade.h"

void PhysicsFacade::setPosition(shared_ptr<GameObject> gameObject, Vec2 position)
{
	gameObject->physicalBody.body.position = position;
}

void PhysicsFacade::updatePosition(shared_ptr<GameObject> gameObject)
{
	gameObject->physicalBody.body.position += gameObject->physicalBody.body.velocity;

}

vector<shared_ptr<GameObject>> PhysicsFacade::getCollisions(shared_ptr<GameObject> objectA, std::vector<shared_ptr<GameObject>> objectList)
{
	Collision col;
	return col.getCollisions(objectA, objectList);
}
