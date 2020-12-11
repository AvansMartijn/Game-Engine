#include "pch.h"
#include "MoveExtension.h"
#include "Physics.h"
#include "Utilities.h"

MoveExtension::MoveExtension() {
	type = "MoveExtension";
}

void MoveExtension::move(float movementX, float movementY) {
	Vec2 vel = Physics::getInstance().getLinearVelocity(_subject);
	vel.x = movementX;
	vel.y = movementY;
	currentMovementType = MovementType::RUNNING;

	if (vel.x < 0)
		isLookingToLeft = true;
	else if (vel.x > 0)
		isLookingToLeft = false;

	Physics::getInstance().setLinearVelocity(_subject, vel);
	resetAfkTime();
}

void MoveExtension::moveX(float movementX) {
	Vec2 vel = Physics::getInstance().getLinearVelocity(_subject);
	vel.x = movementX;

	if(currentMovementType != MovementType::JUMPING)
		currentMovementType = MovementType::RUNNING;

	if (vel.x < 0)
		isLookingToLeft = true;
	else if (vel.x > 0)
		isLookingToLeft = false;

	Physics::getInstance().setLinearVelocity(_subject, vel);
	resetAfkTime();
}

void MoveExtension::moveY(float movementY) {
	Vec2 vel = Physics::getInstance().getLinearVelocity(_subject);
	vel.y = movementY;
	currentMovementType = MovementType::JUMPING;

	Physics::getInstance().setLinearVelocity(_subject, vel);
	resetAfkTime();
}

void MoveExtension::updateState() {
	Vec2 vel = Physics::getInstance().getLinearVelocity(_subject);
	if (canJump() && vel.x == 0 && vel.y == 0) {
		if (Utilities::getInstance().isEnoughTimeElapsed(3000, _afkTime))
			currentMovementType = MovementType::AFK;
		else if (currentMovementType != MovementType::AFK)
			currentMovementType = MovementType::IDLE;
	}
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

void MoveExtension::resetAfkTime() {
	_afkTime = std::chrono::steady_clock::now();
}