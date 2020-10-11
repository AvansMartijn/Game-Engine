#pragma once
#include "AbstractBehaviour.h"

/// <summary>
/// Attack behavior
/// </summary>
class BehaviourAttack: public AbstractBehaviour
{
public:
	using AbstractBehaviour::AbstractBehaviour;

	/// <summary>
	/// Execute the behaviour.
	/// </summary>
	void execute();

	/// <summary>
	/// See if the object can be attacked.
	/// </summary>
	/// <returns>Can the object be attacked.</returns>
	bool canAttack();
};

