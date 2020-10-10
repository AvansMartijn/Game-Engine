#pragma once
#include "AbstractGameObjectExtension.h"
class AbstractCollisionResolutionExtension : public AbstractGameObjectExtension
{
public:
	virtual bool isDefault() = 0;
	virtual void resolveCollision(shared_ptr<GameObject> otherObject) = 0;
};

