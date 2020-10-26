#pragma once
#include "AbstractBehaviour.h"

/// <summary>
/// Sees enemy ai behavior
/// </summary>
class BehaviourSeesEnemy : public AbstractBehaviour
{
public:
	using AbstractBehaviour::AbstractBehaviour;

	/// <summary>
	/// Execute the behaviour.
	/// </summary>
	void execute();
};

