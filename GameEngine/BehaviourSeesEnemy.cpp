#include "pch.h"
#include "BehaviourSeesEnemy.h"

void BehaviourSeesEnemy::execute() {
	float lookX = 10;
	float lookY = 2;

	// TODO: NO BOX2D
	float subjectX = _self->body.b2body->GetPosition().x;
	float subjectY = _self->body.b2body->GetPosition().y;

	float playerX = Scene::getInstance().getPlayer()->body.b2body->GetPosition().x;
	float playerY = Scene::getInstance().getPlayer()->body.b2body->GetPosition().y;

	float fovStartX = subjectX;
	float fovEndX = subjectX + lookX;
	float fovStartY = subjectY - lookY;
	float fovEndY = subjectY + lookY;

	if (_self->hasExtension(typeid(MoveExtension))) {
		shared_ptr<MoveExtension> moveExtension = _self->getExtension<MoveExtension>();

		if (!moveExtension->isLookingToRight) {
			fovStartX = subjectX - lookX;
			fovEndX = subjectX;
		}
	}
	bool playerInViewX = playerX >= fovStartX && playerX <= fovEndX;
	bool playerInViewY = playerY >= fovStartY && playerY <= fovEndY;

	this->executeNextBehaviour(playerInViewX && playerInViewY);
}
