#pragma once
#include "AbstractCollisionResolutionExtension.h"
#include "PhysicsFacade.h"
class CollisionResolutionDefaultExtension : public AbstractCollisionResolutionExtension
{
private:
	PhysicsFacade _physicsFacade;
public:
	CollisionResolutionDefaultExtension();

	bool isDefault();
	void resolveCollision(shared_ptr<GameObject> otherObject);

	static AbstractGameObjectExtension* __stdcall create() { return new CollisionResolutionDefaultExtension(); }
};

