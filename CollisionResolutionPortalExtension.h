#pragma once
#include "AbstractCollisionResolutionExtension.h"
#include "PhysicsFacade.h"

class CollisionResolutionPortalExtension : public AbstractCollisionResolutionExtension
{
public:

	CollisionResolutionPortalExtension();

	bool isDefault();
	void resolveCollision(shared_ptr<GameObject> otherObject);

	static AbstractGameObjectExtension* __stdcall create() { return new CollisionResolutionPortalExtension(); }
};

