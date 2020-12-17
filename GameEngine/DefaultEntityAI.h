#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_DefaultEntityAI __declspec(dllexport)
#else
#define GAMEENGINE_DefaultEntityAI __declspec(dllimport)
#endif
#include "AbstractEntityAI.h"
#include "AbstractBehaviour.h"
#include "BehaviourIdle.h"
#include "BehaviourSeesEnemy.h"
#include "BehaviourAttack.h"
#include "BehaviourRotate.h"
#include "BehaviourMove.h"

class GAMEENGINE_DefaultEntityAI DefaultEntityAI : public AbstractEntityAI {
private:
	unique_ptr<BehaviourIdle> _idleBehaviour;
	unique_ptr<BehaviourSeesEnemy> _seesEnemyBehaviour;
	unique_ptr<BehaviourRotate> _rotateEnemyBehaviour;
	unique_ptr<BehaviourMove> _moveEnemyBehaviour;
	unique_ptr<BehaviourAttack> _attackPlayerBehaviour;
public:
	/// <summary>
	/// Create the behaviour tree.
	/// </summary>
	/// <param name="self">The player</param>
	void createBehaviourTree(GameObject* self);
};

