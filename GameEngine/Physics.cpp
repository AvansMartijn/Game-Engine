#include "pch.h"
#include "Physics.h"
#include <Box2d/Box2d.h>


Physics::Physics() : gravity(0.0f, -10.0f), world(gravity) {
}

void Physics::AddBody(shared_ptr<GameObject> obj, int x, int y, bool fixed) {
	if (fixed) {
		b2BodyDef bodyDef;
		bodyDef.position.Set((float32) x, (float32) y);
		b2Body* body = world.CreateBody(&bodyDef);
		obj->b2body = body;
		b2PolygonShape box;
		box.SetAsBox(10.0f, 50.0f);
		obj->b2body->CreateFixture(&box, 0.0f);

	}
	else {
		b2BodyDef bodyDef;
		bodyDef.type = b2_dynamicBody;
		bodyDef.position.Set((float32)x, (float32)y);
		b2Body* body = world.CreateBody(&bodyDef);
		obj->b2body = body;
		b2PolygonShape dynamicBox;
		dynamicBox.SetAsBox(1.0f, 1.0f);
		b2FixtureDef fixtureDef;
		fixtureDef.shape = &dynamicBox;
		fixtureDef.density = 1.0f;
		fixtureDef.friction = 0.3f;
		body->CreateFixture(&fixtureDef);
	}
}
//void Physics::changeVelocity(shared_ptr<GameObject> object, const Vec2& velocity) {
//	object->physicalBody.body.velocity = velocity;
//}




//void Physics::setPosition(shared_ptr<GameObject> gameObject, const Vec2& position) {
//	//todo: refactor to single statement after AABB refactored to polygonShapes
//	int width = gameObject->physicalBody.shape.getWidth();
//	int height = gameObject->physicalBody.shape.getHeight();
//	gameObject->physicalBody.body.position = position;
//	gameObject->physicalBody.shape.min = position;
//	gameObject->physicalBody.shape.max = { position.x + width, position.y + height };
//}
//
//void Physics::updatePosition(shared_ptr<GameObject> gameObject) {
//	//todo: refactor to single statement after AABB refactored to polygonShapes
//	gameObject->physicalBody.shape.min += gameObject->physicalBody.body.velocity;
//	gameObject->physicalBody.shape.max += gameObject->physicalBody.body.velocity;
//	gameObject->physicalBody.body.position += gameObject->physicalBody.body.velocity;
//}
//
//void Physics::addGravityForce(shared_ptr<GameObject> object)
//{
//	//todo: calc max downward velocity based on object properties
//	if (object->physicalBody.body.velocity.y < 40) {
//		object->physicalBody.body.velocity.y += 0.2;
//	}
//}

