#pragma once
#include "AbstractBehaviour.h"
#include "EntityMovementExtension.h"

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
};

