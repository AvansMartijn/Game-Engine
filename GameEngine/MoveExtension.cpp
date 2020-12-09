#include "pch.h"
#include "MoveExtension.h"

const std::string MoveExtension::LOOK_RIGHT = "Look_Right";
const std::string MoveExtension::RUN_RIGHT = "Running_Right";
const std::string MoveExtension::JUMP_RIGHT = "Jump_Right";
const std::string MoveExtension::FALL_RIGHT = "Fall_Right";
const std::string MoveExtension::LOOK_LEFT = "Look_Left";
const std::string MoveExtension::RUN_LEFT = "Running_Left";
const std::string MoveExtension::JUMP_LEFT = "Jump_Left";
const std::string MoveExtension::FALL_LEFT = "Fall_Left";

MoveExtension::MoveExtension() {
	type = "MoveExtension";
}

void MoveExtension::move(float movementX, float movementY) {
	// TODO: NO Box2D
	b2Vec2 vel = _subject->body.b2body->GetLinearVelocity();
	vel.x = movementX;
	vel.y = movementY;

	currentMovementType = MovementTypes::RUNNING;

	_subject->body.b2body->SetLinearVelocity(vel);

}

bool MoveExtension::canJump() {
	return jumpCounter > 0;
}

void MoveExtension::reset() {
	jumpCounter = 0;
}