#pragma once
#include "AbstractCollisionResolutionExtension.h"
#include "GameObject.h"
//#include "PhysicsFacade.h"

class CollisionResolutionPortalExtension : public AbstractCollisionResolutionExtension
{
private:
	//PhysicsFacade _physicsFacade;
public:
	CollisionResolutionPortalExtension();

	shared_ptr<GameObject> linkedPortal;
	bool isDefault();
	void resolveCollision(shared_ptr<GameObject> otherObject);

	static AbstractGameObjectExtension* __stdcall create() { return new CollisionResolutionPortalExtension(); }
};

