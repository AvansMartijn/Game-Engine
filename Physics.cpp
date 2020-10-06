#include "Physics.h"

void Physics::changeVelocity(shared_ptr<GameObject> object, Vec2 velocity) {
	object->physicalBody.body.velocity = velocity;
}

void Physics::changePosition(shared_ptr<GameObject> object, Vec2 position) {
	object->physicalBody.body.position = position;
}