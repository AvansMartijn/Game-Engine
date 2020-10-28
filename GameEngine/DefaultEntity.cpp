#include "pch.h"
#include "DefaultEntityAI.h"
#include "AbstractEntityAI.h"
#include "AbstractBehaviour.h"
#include "BehaviourIdle.h"
#include "BehaviourSeesEnemy.h"
#include "BehaviourAttack.h"

void DefaultEntityAI::createBehaviourTree(shared_ptr<GameObject> self, shared_ptr<vector<GameObject>> scene) {
	// Behaviour
	shared_ptr<BehaviourIdle> idle = make_shared<BehaviourIdle>(BehaviourIdle(self, scene));


	shared_ptr<BehaviourSeesEnemy> seesEnemy = make_shared<BehaviourSeesEnemy>(BehaviourSeesEnemy(self, scene));
	idle->behaviourTrue = seesEnemy;

	shared_ptr<BehaviourAttack> attack = make_shared<BehaviourAttack>(BehaviourAttack(self, scene));
	seesEnemy->behaviourTrue = attack;
	seesEnemy->behaviourFalse = idle;

	attack->behaviourTrue = idle;

	shared_ptr<AbstractBehaviour> firstBehaviour = idle;
	firstBehaviour->execute();
}
