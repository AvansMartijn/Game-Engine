#pragma once
#include "AbstractBehaviour.h"

/// <summary>
/// Move ai behavior
/// </summary>
class BehaviourMove: public AbstractBehaviour
{
public:
	using AbstractBehaviour::AbstractBehaviour;

	void execute();

	bool isMovable();

	bool isWallHit();
};

