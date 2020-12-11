#include "pch.h"
#include "MoveExtension.h"
#include "Physics.h"

MoveExtension::MoveExtension() {
	type = "MoveExtension";
}

void MoveExtension::move(float movementX, float movementY) {
	Vec2 vel = Physics::getInstance().getLinearVelocity(_subject);
	vel.x = movementX;
	vel.y = movementY;
	currentMovementType = MovementType::RUNNING;

	if (vel.x < 0)
		isLookingToRight = false;
	else if (vel.x > 0)
		isLookingToRight = true;

	Physics::getInstance().setLinearVelocity(_subject, vel);
}

void MoveExtension::moveX(float movementX) {
	Vec2 vel = Physics::getInstance().getLinearVelocity(_subject);
	vel.x = movementX;

	if(currentMovementType != MovementType::JUMPING)
		currentMovementType = MovementType::RUNNING;

	if (vel.x < 0)
		isLookingToRight = false;
	else if (vel.x > 0)
		isLookingToRight = true;

	Physics::getInstance().setLinearVelocity(_subject, vel);
}

void MoveExtension::moveY(float movementY) {
	Vec2 vel = Physics::getInstance().getLinearVelocity(_subject);
	vel.y = movementY;
	currentMovementType = MovementType::JUMPING;

	Physics::getInstance().setLinearVelocity(_subject, vel);
}

void MoveExtension::updateState() {
	Vec2 vel = Physics::getInstance().getLinearVelocity(_subject);

	if (canJump() && vel.x == 0 && vel.y == 0)
		currentMovementType = MovementType::IDLE;
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