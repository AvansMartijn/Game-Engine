#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_CollisionResolutionPortalExtension __declspec(dllexport)
#else
#define GAMEENGINE_CollisionResolutionPortalExtension __declspec(dllimport)
#endif

#include "AbstractCollisionResolutionExtension.h"
#include "GameObject.h"
#include "Physics.h"
//#include "PhysicsFacade.h"

class GAMEENGINE_CollisionResolutionPortalExtension CollisionResolutionPortalExtension : public AbstractCollisionResolutionExtension
{
private:
	//PhysicsFacade _physicsFacade;	
	shared_ptr<GameObject> _linkedPortal;
public:
	CollisionResolutionPortalExtension();

	bool isDefault();
	void resolveCollision(shared_ptr<GameObject> inputObject);
	void link(shared_ptr<GameObject> linkedPortal);

	static AbstractGameObjectExtension* __stdcall create() { return new CollisionResolutionPortalExtension(); }
};

