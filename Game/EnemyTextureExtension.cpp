#include "EnemyTextureExtension.h"
#include <Scene.h>

EnemyTextureExtension::EnemyTextureExtension() {
	type = "EnemyTextureExtension";
}

void EnemyTextureExtension::calculateTextures() {
	std::string currentState = "";

	if (!_subject->hasExtension(typeid(MoveExtension)))
		return;

	shared_ptr<MoveExtension> moveExtension = _subject->getExtension<MoveExtension>();

	if (moveExtension->isLookingToRight) {
		if (moveExtension->currentMovementType == MovementTypes::IDLE)
			currentState = MoveExtension::LOOK_RIGHT;
		else if (moveExtension->currentMovementType == MovementTypes::JUMPING) {
			if (_subject->body.b2body->GetLinearVelocity().y == 0)
				currentState = MoveExtension::LOOK_RIGHT;
			else
				currentState = MoveExtension::JUMP_RIGHT;
		}
		else if (moveExtension->currentMovementType == MovementTypes::RUNNING) {
			if (_subject->body.b2body->GetLinearVelocity().x == 0)
				currentState = MoveExtension::LOOK_RIGHT;
			else
				currentState = MoveExtension::RUN_RIGHT;
		}
	}
	else {
		if (moveExtension->currentMovementType == MovementTypes::IDLE)
			currentState = MoveExtension::LOOK_LEFT;
		else if (moveExtension->currentMovementType == MovementTypes::JUMPING) {
			if (_subject->body.b2body->GetLinearVelocity().y == 0)
				currentState = MoveExtension::LOOK_LEFT;
			else
				currentState = MoveExtension::JUMP_LEFT;
		}
		else if (moveExtension->currentMovementType == MovementTypes::RUNNING) {
			if (_subject->body.b2body->GetLinearVelocity().x == 0)
				currentState = MoveExtension::LOOK_LEFT;
			else
				currentState = MoveExtension::RUN_LEFT;
		}
	}

	_subject->currentState = currentState;
}