#pragma once
#include <list>
#include "GameObject.h"

class AbstractEntityAI
{
public:
	virtual void createBehaviourTree(GameObject* self, std::list<GameObject>* scene) = 0;
};
