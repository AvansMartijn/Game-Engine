#include "pch.h"
#include "DefaultEntityAI.h"
#include <thread>


void DefaultEntityAI::createBehaviourTree(shared_ptr<GameObject> self) {
	// Behaviour
	_behaviourIdle = make_shared<BehaviourIdle>(BehaviourIdle(self));

	shared_ptr<BehaviourSeesEnemy> seesEnemy = make_shared<BehaviourSeesEnemy>(BehaviourSeesEnemy(self));
	_behaviourIdle->behaviourTrue = seesEnemy;

	shared_ptr<BehaviourAttack> attackPlayer = make_shared<BehaviourAttack>(BehaviourAttack(self));

	shared_ptr<BehaviourMove> moveEnemy = make_shared<BehaviourMove>(BehaviourMove(self));
	moveEnemy->behaviourFalse = attackPlayer;

	shared_ptr<BehaviourRotate> rotateEnemy = make_shared<BehaviourRotate>(BehaviourRotate(self, 2000));
	seesEnemy->behaviourTrue = moveEnemy;
	seesEnemy->behaviourFalse = rotateEnemy;

	_currentBehaviour = _behaviourIdle;
}

