#include "PlayerTextureExtension.h"
#include <Scene.h>
#include <Physics.h>

PlayerTextureExtension::PlayerTextureExtension() {
	type = "PlayerTextureExtension";
}

void PlayerTextureExtension::calculateTextures() {
	shared_ptr<MoveExtension> moveExtension = Scene::getInstance().getPlayerMoveExtension();
	if (moveExtension->isLookingToRight) {
		if (moveExtension->currentMovementType == MovementTypes::JUMPING) {
			if (Physics::getInstance().getLinearVelocity(Scene::getInstance().getPlayer()).y == 0)
				Scene::getInstance().getPlayer()->currentState = MoveExtension::LOOK_RIGHT;
			else
				Scene::getInstance().getPlayer()->currentState = MoveExtension::JUMP_RIGHT;
		}
		else if (moveExtension->currentMovementType == MovementTypes::RUNNING) {
			if (Physics::getInstance().getLinearVelocity(Scene::getInstance().getPlayer()).x == 0)
				Scene::getInstance().getPlayer()->currentState = MoveExtension::LOOK_RIGHT;
			else
				Scene::getInstance().getPlayer()->currentState = MoveExtension::RUN_RIGHT;
		}
	}
	else {
		if (moveExtension->currentMovementType == MovementTypes::JUMPING) {
			if (Physics::getInstance().getLinearVelocity(Scene::getInstance().getPlayer()).y == 0)
				Scene::getInstance().getPlayer()->currentState = MoveExtension::LOOK_LEFT;
			else
				Scene::getInstance().getPlayer()->currentState = MoveExtension::JUMP_LEFT;
		}
		else if (moveExtension->currentMovementType == MovementTypes::RUNNING) {
			if (Physics::getInstance().getLinearVelocity(Scene::getInstance().getPlayer()).x == 0)
				Scene::getInstance().getPlayer()->currentState = MoveExtension::LOOK_LEFT;
			else
				Scene::getInstance().getPlayer()->currentState = MoveExtension::RUN_LEFT;
		}
	}
}