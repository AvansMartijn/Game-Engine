#pragma once
#include "AbstractCollisionResolutionExtension.h"

class CollisionResolutionPortalExtension : AbstractCollisionResolutionExtension
{
public:

	CollisionResolutionPortalExtension();

	bool isDefault();
	void resolveCollition(shared_ptr<GameObject> objectA, shared_ptr<GameObject> objectB);

	static AbstractGameObjectExtension* __stdcall create() { return new CollisionResolutionPortalExtension(); }
};

