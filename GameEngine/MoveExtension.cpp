#include "pch.h"
#include "MoveExtension.h"

MoveExtension::MoveExtension() {
	type = "MoveExtension";
}

void MoveExtension::move(float movementX, float movementY) {
	// TODO: NO Box2D
	b2Vec2 vel = _subject->body.b2body->GetLinearVelocity();
	vel.x = movementX;
	vel.y = movementY;

	currentMovementType = MovementType::RUNNING;

	_subject->body.b2body->SetLinearVelocity(vel);
}

bool MoveExtension::canJump() {
	return jumpCounter > 0;
}

int MoveExtension::getLeftArmCounter() {
	return leftArmCounter;
}
int MoveExtension::getRightArmCounter() {
	return rightArmCounter;
}

void MoveExtension::reset() {
	jumpCounter = 0;
}