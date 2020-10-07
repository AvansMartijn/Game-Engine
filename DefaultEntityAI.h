#pragma once
#include "AbstractEntityAI.h"

class DefaultEntityAI: public AbstractEntityAI
{
public:
	using AbstractEntityAI::AbstractEntityAI;

	void createBehaviourTree(shared_ptr<GameObject> self, shared_ptr<vector<GameObject>> scene);
};

