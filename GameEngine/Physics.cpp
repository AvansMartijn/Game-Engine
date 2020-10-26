#include "pch.h"
#include "Physics.h"

void Physics::changeVelocity(shared_ptr<GameObject> object, const Vec2& velocity) {
	object->physicalBody.body.velocity = velocity;
}

void Physics::setPosition(shared_ptr<GameObject> gameObject, const Vec2& position) {
	//todo: refactor to single statement after AABB refactored to polygonShapes
	int width = gameObject->physicalBody.shape.getWidth();
	int height = gameObject->physicalBody.shape.getHeight();
	gameObject->physicalBody.body.position = position;
	gameObject->physicalBody.shape.min = position;
	gameObject->physicalBody.shape.max = { position.x + width, position.y + height };
}

void Physics::updatePosition(shared_ptr<GameObject> gameObject) {
	//todo: refactor to single statement after AABB refactored to polygonShapes
	gameObject->physicalBody.shape.min += gameObject->physicalBody.body.velocity;
	gameObject->physicalBody.shape.max += gameObject->physicalBody.body.velocity;
	gameObject->physicalBody.body.position += gameObject->physicalBody.body.velocity;
}

void Physics::addGravityForce(shared_ptr<GameObject> object)
{
	//todo: calc max downward velocity based on object properties
	if (object->physicalBody.body.velocity.y < 40) {
		object->physicalBody.body.velocity.y += 0.2;
	}
}

