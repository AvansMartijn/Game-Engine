#pragma once
#include "AbstractCollisionResolutionExtension.h"
#include "PhysicsFacade.h"
class CollisionResolutionDefaultExtension : public AbstractCollisionResolutionExtension
{
	//physics do something(subject, subject)
public:
	CollisionResolutionDefaultExtension();

	bool isDefault();
	void resolveCollision(shared_ptr<GameObject> objectA, shared_ptr<GameObject> objectB);

	static AbstractGameObjectExtension* __stdcall create() { return new CollisionResolutionDefaultExtension(); }
};

