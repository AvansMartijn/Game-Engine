#pragma once
#include "AbstractBehaviour.h"

class BehaviourMove: public AbstractBehaviour
{
public:
	using AbstractBehaviour::AbstractBehaviour;

	void execute();

	bool isMovable();

	bool isWallHit();
};

