#pragma once
#include "AbstractBehaviour.h"

class BehaviourRotate: public AbstractBehaviour
{
public:
	using AbstractBehaviour::AbstractBehaviour;

	void execute();

	bool hasEnoughTimeElapsed();

	bool canRotate();
};

