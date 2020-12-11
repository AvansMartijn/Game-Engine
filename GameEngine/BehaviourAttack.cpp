#include "pch.h"
#include "BehaviourAttack.h"

void BehaviourAttack::execute() {
	shared_ptr<HealthExtension> healthExtension = Scene::getInstance().getPlayer()->getExtension<HealthExtension>();
	shared_ptr<MoveExtension> moveExtension = _self->getExtension<MoveExtension>();

	if (healthExtension != nullptr) {
		healthExtension->reduceHealth(5);

		if (moveExtension != nullptr)
			moveExtension->currentMovementType = MovementType::ATTACKING;

		this->executeNextBehaviour(true);
	}
	
	this->executeNextBehaviour(false);
}