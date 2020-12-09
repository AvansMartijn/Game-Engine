#include "pch.h"
#include "BehaviourAttack.h"

void BehaviourAttack::execute() {
	shared_ptr<HealthExtension> healthExtension = Scene::getInstance().getPlayer()->getExtension<HealthExtension>();
	healthExtension->reduceHealth(1);

	this->executeNextBehaviour(true);
}