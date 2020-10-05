#include "Physics.h"

void Physics::changeVelocity(GameObject object, Vec2 velocity) {
	object.physicalBody.body.velocity = velocity;
}

void Physics::changePosition(GameObject object, Vec2 position) {
	object.physicalBody.body.position = position;
}