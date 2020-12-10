#include "EnemyTextureExtension.h"
#include <Scene.h>
#include <Physics.h>

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
		else if (moveExtension->currentMovementType == MovementTypes::RUNNING) {
			if (Physics::getInstance().getLinearVelocity(_subject).x == 0)
				currentState = MoveExtension::LOOK_RIGHT;
			else
				currentState = MoveExtension::RUN_RIGHT;
		}
		else if (moveExtension->currentMovementType == MovementTypes::ATTACKING)
			currentState = MoveExtension::ATTACK_RIGHT;
	}
	else {
		if (moveExtension->currentMovementType == MovementTypes::IDLE)
			currentState = MoveExtension::LOOK_LEFT;
		else if (moveExtension->currentMovementType == MovementTypes::RUNNING) {
			if (Physics::getInstance().getLinearVelocity(_subject).x == 0)
				currentState = MoveExtension::LOOK_LEFT;
			else
				currentState = MoveExtension::RUN_LEFT;
		}
		else if (moveExtension->currentMovementType == MovementTypes::ATTACKING)
			currentState = MoveExtension::ATTACK_LEFT;
	}

	_subject->currentState = currentState;
}