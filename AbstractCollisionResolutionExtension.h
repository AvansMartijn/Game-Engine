#pragma once
#include "AbstractGameObjectExtension.h"
class AbstractCollisionResolutionExtension : public AbstractGameObjectExtension
{
public:
	virtual bool isDefault() = 0;
	virtual void resolveCollition(shared_ptr<GameObject> objectA , shared_ptr<GameObject> objectB) = 0;
};

