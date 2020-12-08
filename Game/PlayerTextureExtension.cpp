#include "PlayerTextureExtension.h"
#include <Scene.h>
#include "PlayerMoves.h"

PlayerTextureExtension::PlayerTextureExtension() {
	type = "PlayerTextureExtension";
}

void PlayerTextureExtension::calculateTextures() {
	shared_ptr<MoveExtension> moveExtension = Scene::getInstance().getPlayerMoveExtension();
	if (moveExtension->isLookingToRight) {
		if (moveExtension->currentMovementType == MovementTypes::JUMPING) {
			if (Scene::getInstance().getPlayer()->body.b2body->GetLinearVelocity().y == 0)
				Scene::getInstance().getPlayer()->currentState = PlayerMoves::LOOK_RIGHT;
			else
				Scene::getInstance().getPlayer()->currentState = PlayerMoves::JUMP_RIGHT;
		}
		else if (moveExtension->currentMovementType == MovementTypes::RUNNING) {
			if (Scene::getInstance().getPlayer()->body.b2body->GetLinearVelocity().x == 0)
				Scene::getInstance().getPlayer()->currentState = PlayerMoves::LOOK_RIGHT;
			else
				Scene::getInstance().getPlayer()->currentState = PlayerMoves::RUN_RIGHT;
		}
	}
	else {
		if (moveExtension->currentMovementType == MovementTypes::JUMPING) {
			if (Scene::getInstance().getPlayer()->body.b2body->GetLinearVelocity().y == 0)
				Scene::getInstance().getPlayer()->currentState = PlayerMoves::LOOK_LEFT;
			else
				Scene::getInstance().getPlayer()->currentState = PlayerMoves::JUMP_LEFT;
		}
		else if (moveExtension->currentMovementType == MovementTypes::RUNNING) {
			if (Scene::getInstance().getPlayer()->body.b2body->GetLinearVelocity().x == 0)
				Scene::getInstance().getPlayer()->currentState = PlayerMoves::LOOK_LEFT;
			else
				Scene::getInstance().getPlayer()->currentState = PlayerMoves::RUN_LEFT;
		}
	}
}