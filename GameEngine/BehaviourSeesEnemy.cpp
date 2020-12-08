#include "pch.h"
#include "BehaviourSeesEnemy.h"

void BehaviourSeesEnemy::execute() {
	int lookX = 10;
	int lookY = 1;

	// TODO: NO BOX2D
	float subjectX = _self->body.b2body->GetPosition().x;
	float subjectY = _self->body.b2body->GetPosition().y;

	float playerX = Scene::getInstance().getPlayer()->body.b2body->GetPosition().x;
	float playerY = Scene::getInstance().getPlayer()->body.b2body->GetPosition().y;

	shared_ptr<EntityMovementExtension> movementExtension = _self->getExtension<EntityMovementExtension>();

	int fovStartX = subjectX;
	int fovEndX = subjectX + lookX;
	int fovStartY = subjectY - lookY;
	int fovEndY = subjectY + lookY;
	if (!movementExtension->isLookingRight) {
		fovStartX = subjectX - lookX;
		fovEndX = subjectX;
	}

	bool playerInViewX = playerX >= fovStartX && playerX <= fovEndX;
	bool playerInViewY = playerY >= fovStartY && playerY <= fovEndY;

	this->executeNextBehaviour(playerInViewX && playerInViewY);
}
