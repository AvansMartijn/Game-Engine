#include "pch.h"
#include "Body.h"

Body::Body() {
	canJump = 0;
}

Vec2 Body::getLinearVelocity() {
	const b2Vec2& linVel = _body->GetLinearVelocity();

	return { linVel.x, linVel.y };
}

void Body::setLinearVelocity(const Vec2& vel) {
	_body->SetLinearVelocity({ vel.x, vel.y });
}

Vec2 Body::getPosition() {
	const b2Vec2& position = _body->GetPosition();

	return { position.x, position.y };
}

void Body::setTransform(const Vec2& position, float angle) {
	const b2Vec2& b2Position = b2Vec2{ position.x, position.y };
	_body->SetTransform(b2Position, angle);
}

float Body::getAngle() {
	return _body->GetAngle();
}

BodyType Body::getType() {
	BodyType bodyType = BodyType::staticBody;

	b2BodyType b2BodyType = _body->GetType();
	switch (b2BodyType) {
	case b2_staticBody:
		bodyType = BodyType::staticBody;

		break;
	case b2_kinematicBody:
		bodyType = BodyType::kinematicBody;

		break;
	case b2_dynamicBody:
		bodyType = BodyType::dynamicBody;

		break;
	default:
		break;
	}

	return bodyType;
}

void Body::setType(BodyType bodyType) {
	b2BodyType b2BodyType = b2BodyType::b2_staticBody;
	switch (bodyType) {
	case staticBody:
		b2BodyType = b2BodyType::b2_staticBody;

		break;
	case kinematicBody:
		b2BodyType = b2BodyType::b2_kinematicBody;

		break;
	case dynamicBody:
		b2BodyType = b2BodyType::b2_dynamicBody;

		break;
	default:
		break;
	}
	_body->SetType(b2BodyType);
}

void Body::applyLinearImpulseToCenter(const Vec2& impulse, bool wake) {
	_body->ApplyLinearImpulseToCenter(b2Vec2{ impulse.x, impulse.y }, wake);
}

void Body::setBody(b2Body* body) {
	_body = body;
}

b2Body* Body::getOriginal() {
	return _body;
}

CustomUserData* Body::getUserData() {
	return (CustomUserData*)_body->GetUserData().pointer;
}