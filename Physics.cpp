#include "Physics.h"

void Physics::changeVelocity(shared_ptr<GameObject> object, Vec2 velocity) {
	object->physicalBody.body.velocity = velocity;
}

void Physics::setPosition(shared_ptr<GameObject> object, Vec2 position) {
	object->physicalBody.body.position = position;
}

void Physics::updatePosition(shared_ptr<GameObject> object) {
	object->physicalBody.body.position += object->physicalBody.body.velocity;
}