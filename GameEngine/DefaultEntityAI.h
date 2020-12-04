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

class GAMEENGINE_DefaultEntityAI DefaultEntityAI : public AbstractEntityAI
{
private:
	shared_ptr<BehaviourIdle> _behaviourIdle;
public:
	/// <summary>
	/// Create the behaviour tree.
	/// </summary>
	/// <param name="self">The player</param>
	void createBehaviourTree(shared_ptr<GameObject> self);
};

