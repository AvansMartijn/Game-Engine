#pragma once
#include "AbstractEntityAI.h"

class DefaultEntityAI: public AbstractEntityAI
{
public:
	using AbstractEntityAI::AbstractEntityAI;

	/// <summary>
	/// Create the behaviour tree.
	/// </summary>
	/// <param name="self">The player</param>
	/// <param name="scene">All the game objects</param>
	void createBehaviourTree(shared_ptr<GameObject> self, shared_ptr<vector<GameObject>> scene);
};

