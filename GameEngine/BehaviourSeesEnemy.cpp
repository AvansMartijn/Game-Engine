#include "pch.h"
#include "BehaviourSeesEnemy.h"

void BehaviourSeesEnemy::execute() {
	float lookX = 5;
	float lookY = 2;

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
			fovEndX = subjectX;
		}
	}
	bool playerInViewX = playerX >= fovStartX && playerX <= fovEndX;
	bool playerInViewY = playerY >= fovStartY && playerY <= fovEndY;

	this->executeNextBehaviour(playerInViewX && playerInViewY);
}
