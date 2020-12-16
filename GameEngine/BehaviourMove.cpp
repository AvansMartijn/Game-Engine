#include "pch.h"
#include "BehaviourMove.h"

void BehaviourMove::execute() {
	MoveExtension* extension = _self->getExtension<MoveExtension>();

	if (_self->body.getLinearVelocity().y == 0) {

		if (!isPlayerInAttackRange()) {
			extension->move(extension->isLookingToLeft ? -2.0f : 2.0f, 0.0f);

			this->executeNextBehaviour(true);
		}
		else
			this->executeNextBehaviour(false);
	}
}

bool BehaviourMove::isPlayerInAttackRange() {
	float lookX = 1;
	float lookY = 1;

	float subjectX = _self->body.getPosition().x;
	float subjectY = _self->body.getPosition().y;
	
	float playerX = Scene::getInstance().getPlayer()->body.getPosition().x;
	float playerY = Scene::getInstance().getPlayer()->body.getPosition().y;

	float fovStartX = subjectX;
	float fovEndX = subjectX + lookX;
	float fovStartY = subjectY - lookY;
	float fovEndY = subjectY + lookY;

	if (_self->hasExtension(typeid(MoveExtension))) {
		MoveExtension* moveExtension = _self->getExtension<MoveExtension>();

		if (moveExtension->isLookingToLeft) {
			fovStartX = subjectX - lookX;
			fovEndX = subjectX + 0.5f;
		}
	}
	bool playerInViewX = playerX >= fovStartX && playerX <= fovEndX;
	bool playerInViewY = playerY >= fovStartY && playerY <= fovEndY;

	return playerInViewX && playerInViewY;
}