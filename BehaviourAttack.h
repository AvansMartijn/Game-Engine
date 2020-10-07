#pragma once
#include "AbstractBehaviour.h"

class BehaviourAttack: public AbstractBehaviour
{
public:
	using AbstractBehaviour::AbstractBehaviour;

	void execute();

	bool canAttack();
};

