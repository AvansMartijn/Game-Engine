#pragma once
#include <list>
#include "GameObject.h"

/// <summary>
/// Abstract class for entity ai
/// </summary>
class AbstractEntityAI
{
public:
	AbstractEntityAI();

	/// <summary>
	/// Create the behaviour tree.
	/// </summary>
	/// <param name="self">The player</param>
	/// <param name="scene">All the game objects</param>
	virtual void createBehaviourTree(shared_ptr<GameObject> self, shared_ptr<vector<GameObject>> scene) = 0;
};
