#include "pch.h"
#include "MoveExtension.h"
#include "Physics.h"
#include "Utilities.h"

MoveExtension::MoveExtension() {
	type = getType();
}

void MoveExtension::move(float movementX, float movementY) {
	Vec2 vel = _subject->body.getLinearVelocity();
	vel.x = movementX;
	vel.y = movementY;

	if (_subject->hasExtension(typeid(CanWieldExtension)))
		_subject->getExtension<CanWieldExtension>()->setShouldRender(true);

	if (currentMovementType != MovementType::JUMPING && currentMovementType != MovementType::HURTING)
		currentMovementType = MovementType::RUNNING;

	if (vel.x < 0)
		isLookingToLeft = true;
	else if (vel.x > 0)
		isLookingToLeft = false;

	_subject->body.setLinearVelocity(vel);
	resetAfkTime();
}

void MoveExtension::moveX(float movementX) {
	Vec2 vel = _subject->body.getLinearVelocity();
	vel.x = movementX;

	if(currentMovementType != MovementType::JUMPING)
		currentMovementType = MovementType::RUNNING;

	if (_subject->hasExtension(typeid(CanWieldExtension)))
		_subject->getExtension<CanWieldExtension>()->setShouldRender(true);

	if (vel.x < 0)
		isLookingToLeft = true;
	else if (vel.x > 0)
		isLookingToLeft = false;

	_subject->body.setLinearVelocity(vel);
	resetAfkTime();
}

void MoveExtension::moveY(float movementY) {
	Vec2 vel = _subject->body.getLinearVelocity();
	vel.y = movementY;
	
	currentMovementType = MovementType::JUMPING;

	if (_subject->hasExtension(typeid(CanWieldExtension)))
		_subject->getExtension<CanWieldExtension>()->setShouldRender(true);

	_subject->body.setLinearVelocity(vel);
	resetAfkTime();
}

void MoveExtension::updateState() {
	Vec2 vel = _subject->body.getLinearVelocity();
	if (canJump() && vel.x == 0 && vel.y == 0 && currentMovementType != MovementType::HURTING) {
		if (_subject->hasExtension(typeid(CanWieldExtension))) {
			CanWieldExtension* canWieldExtension = _subject->getExtension<CanWieldExtension>();

			if (canWieldExtension->hasItems()) {
				if (currentMovementType == MovementType::AFK)
					canWieldExtension->getCurrentItem()->shouldRender = false;
				else
					canWieldExtension->getCurrentItem()->shouldRender = true;
			}
		}

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

void MoveExtension::fillProperties(std::map<std::string, ExtensionProperty> propertiess) {
}