#pragma once
#include "AbstractBehaviour.h"
#include "Scene.h"
#include "Physics.h"

/// <summary>
/// Move ai behavior
/// </summary>
class BehaviourMove : public AbstractBehaviour {
public:
	using AbstractBehaviour::AbstractBehaviour;

	/// <summary>
	/// Execute the behaviour.
	/// </summary>
	void execute();

	/// <summary>
	/// Checks if the player is in attack range.
	/// </summary>
	/// <returns>If the player is in attack range.</returns>
	bool isPlayerInAttackRange();
};

