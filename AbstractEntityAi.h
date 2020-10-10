#pragma once
#include <list>
#include "GameObject.h"

class AbstractEntityAI
{
public:
	AbstractEntityAI();
	virtual void createBehaviourTree(shared_ptr<GameObject> self, shared_ptr<vector<GameObject>> scene) = 0;
};
