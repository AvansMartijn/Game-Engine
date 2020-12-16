#include "pch.h"
#include "DefaultEntityAI.h"
#include <thread>

void DefaultEntityAI::createBehaviourTree(shared_ptr<GameObject> self) {
	_idleBehaviour = make_unique<BehaviourIdle>(self);

	_seesEnemyBehaviour = make_unique<BehaviourSeesEnemy>(self);
	_idleBehaviour->behaviourTrue = _seesEnemyBehaviour.get();

	_attackPlayerBehaviour = make_unique<BehaviourAttack>(self);

	_moveEnemyBehaviour = make_unique<BehaviourMove>(self);
	_moveEnemyBehaviour->behaviourFalse = _attackPlayerBehaviour.get();

	_rotateEnemyBehaviour = make_unique<BehaviourRotate>(self, 2000);
	_seesEnemyBehaviour->behaviourTrue = _moveEnemyBehaviour.get();
	_seesEnemyBehaviour->behaviourFalse = _rotateEnemyBehaviour.get();

	_currentBehaviour = _idleBehaviour.get();
}

