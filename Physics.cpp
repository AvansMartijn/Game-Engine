#include "Physics.h"

void Physics::changeVelocity(shared_ptr<GameObject> object, Vec2 velocity) {
	object->physicalBody.body.velocity = velocity;
}

void Physics::setPosition(shared_ptr<GameObject> gameObject, Vec2 position) {
	int width = gameObject->physicalBody.shape.getWidth();
	int height = gameObject->physicalBody.shape.getHeight();
	gameObject->physicalBody.body.position = position;
	gameObject->physicalBody.shape.min = position;
	gameObject->physicalBody.shape.max = { position.x + width, position.y + height };
}

void Physics::updatePosition(shared_ptr<GameObject> gameObject) {
	gameObject->physicalBody.shape.min += gameObject->physicalBody.body.velocity;
	gameObject->physicalBody.shape.max += gameObject->physicalBody.body.velocity;
	gameObject->physicalBody.body.position += gameObject->physicalBody.body.velocity;
}