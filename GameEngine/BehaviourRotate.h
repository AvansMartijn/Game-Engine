#pragma once
#include "AbstractBehaviour.h"

/// <summary>
/// Rotate ai behavior
/// </summary>
class BehaviourRotate : public AbstractBehaviour
{
public:
	using AbstractBehaviour::AbstractBehaviour;

	/// <summary>
	/// Execute the behaviour.
	/// </summary>
	void execute();

	/// <summary>
	/// If enough time has elapsed for the next rotation.
	/// </summary>
	/// <returns>If enough time has elapsed</returns>
	bool hasEnoughTimeElapsed();

	/// <summary>
	/// Looks if the object can be rotated.
	/// </summary>
	/// <returns>If the object can be rotated</returns>
	bool canRotate();
};

