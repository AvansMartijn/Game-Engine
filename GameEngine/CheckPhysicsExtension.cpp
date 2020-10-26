#include "pch.h"
#include "CheckPhysicsExtension.h"
#include "CollisionResolutionDefaultExtension.h"

CheckPhysicsExtension::CheckPhysicsExtension() {
	type = "CheckPhysicsExtension";
}

void CheckPhysicsExtension::doPhysics(vector<shared_ptr<GameObject>> gameObjectList)
{
	//gravity
	_physicsfacade.addGravityForce(_subject);
	//collision
	vector<shared_ptr<GameObject>> collisionList = _physicsfacade.getCollisions(_subject, gameObjectList);
	for (auto& obj : collisionList) {

		if (obj->hasExtension(typeid(AbstractCollisionResolutionExtension))) {
			shared_ptr<AbstractCollisionResolutionExtension> resolution = dynamic_pointer_cast<AbstractCollisionResolutionExtension>(obj->getExtension(typeid(AbstractCollisionResolutionExtension)));
			if (!resolution->isDefault()) {
				resolution->resolveCollision(_subject);
			}
			else {
				shared_ptr<AbstractCollisionResolutionExtension> resolution = dynamic_pointer_cast<AbstractCollisionResolutionExtension>(_subject->getExtension(typeid(AbstractCollisionResolutionExtension)));
				resolution->resolveCollision(obj);
			}

		}
	}



}

