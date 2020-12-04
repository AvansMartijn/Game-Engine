#include "pch.h"
#include "DefaultEntityAI.h"
#include <thread>


void DefaultEntityAI::createBehaviourTree(shared_ptr<GameObject> self) {
	// Behaviour
	_behaviourIdle = make_shared<BehaviourIdle>(BehaviourIdle(self));

	//shared_ptr<BehaviourSeesEnemy> seesEnemy = make_shared<BehaviourSeesEnemy>(BehaviourSeesEnemy(self));
	//idle->behaviourTrue = seesEnemy;

	//shared_ptr<BehaviourAttack> attack = make_shared<BehaviourAttack>(BehaviourAttack(self));
	//seesEnemy->behaviourTrue = attack;
	//seesEnemy->behaviourFalse = idle;

	//attack->behaviourTrue = idle;

	//shared_ptr<AbstractBehaviour> firstBehaviour = idle;
	//firstBehaviour->execute();

	_currentBehaviour = _behaviourIdle;
}

