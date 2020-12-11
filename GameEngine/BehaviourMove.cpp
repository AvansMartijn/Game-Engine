#include "pch.h"
#include "BehaviourMove.h"

void BehaviourMove::execute() {
	shared_ptr<MoveExtension> extension = _self->getExtension<MoveExtension>();

	if (_self->body.b2body->GetLinearVelocity().y == 0) {

		if (!isPlayerInAttackRange()) {
			extension->move(extension->isLookingToRight ? 2 : -2, 0);

			this->executeNextBehaviour(true);
		}
		else
			this->executeNextBehaviour(false);
	}
}

bool BehaviourMove::isPlayerInAttackRange() {
	float lookX = 1;
	float lookY = 1;

	float subjectX = Physics::getInstance().getPosition(_self).x;
	float subjectY = Physics::getInstance().getPosition(_self).y;
	
	float playerX = Physics::getInstance().getPosition(Scene::getInstance().getPlayer()).x;
	float playerY = Physics::getInstance().getPosition(Scene::getInstance().getPlayer()).y;

	float fovStartX = subjectX;
	float fovEndX = subjectX + lookX;
	float fovStartY = subjectY - lookY;
	float fovEndY = subjectY + lookY;

	if (_self->hasExtension(typeid(MoveExtension))) {
		shared_ptr<MoveExtension> moveExtension = _self->getExtension<MoveExtension>();

		if (!moveExtension->isLookingToRight) {
			fovStartX = subjectX - lookX;
			fovEndX = subjectX + 0.5f;
		}
	}
	bool playerInViewX = playerX >= fovStartX && playerX <= fovEndX;
	bool playerInViewY = playerY >= fovStartY && playerY <= fovEndY;

	return playerInViewX && playerInViewY;
}