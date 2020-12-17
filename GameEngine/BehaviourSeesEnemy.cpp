#include "pch.h"
#include "BehaviourSeesEnemy.h"

void BehaviourSeesEnemy::execute() {
	float lookX = 10;
	float lookY = 2;

	float subjectX = _self->body.getPosition().x;
	float subjectY = _self->body.getPosition().y;

	float playerX = Scene::getInstance().getPlayer()->body.getPosition().x;
	float playerY = Scene::getInstance().getPlayer()->body.getPosition().y;

	float fovStartX = subjectX;
	float fovStartY = subjectY - lookY;
	float fovEndX = subjectX + lookX;
	float fovEndY = subjectY + lookY;

	if (_self->hasExtension(typeid(MoveExtension))) {
		MoveExtension* moveExtension = _self->getExtension<MoveExtension>();

		if (moveExtension->isLookingToLeft) {
			fovStartX = subjectX - lookX;
			fovEndX = subjectX;
		}
	}
	bool playerInViewX = playerX >= fovStartX && playerX <= fovEndX;
	bool playerInViewY = playerY >= fovStartY && playerY <= fovEndY;

	this->executeNextBehaviour(playerInViewX && playerInViewY);
}
