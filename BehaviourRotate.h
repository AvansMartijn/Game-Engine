#pragma once
#include "AbstractBehaviour.h"

/// <summary>
/// Rotate ai behavior
/// </summary>
class BehaviourRotate: public AbstractBehaviour
{
public:
	using AbstractBehaviour::AbstractBehaviour;

	void execute();

	bool hasEnoughTimeElapsed();

	bool canRotate();
};

