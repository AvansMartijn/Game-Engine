#include "pch.h"
#include "CheckPhysicsExtension.h"
#include "CollisionResolutionDefaultExtension.h"
#include "Physics.h"

//TODO: KAN DEZE WEG?
CheckPhysicsExtension::CheckPhysicsExtension() {
	type = "CheckPhysicsExtension";
}

void CheckPhysicsExtension::doPhysics() {
	//_subject->body.b2body->GetContactList();
	//gravity
	//_physicsfacade.addGravityForce(_subject);
	////collision
	//vector<shared_ptr<GameObject>> collisionList = _physicsfacade.getCollisions(_subject, gameObjectList);
	//for (shared_ptr<GameObject>& obj : collisionList) {

	//	if (obj->hasExtension(typeid(AbstractCollisionResolutionExtension))) {
	//		shared_ptr<AbstractCollisionResolutionExtension> resolution = dynamic_pointer_cast<AbstractCollisionResolutionExtension>(obj->getExtension(typeid(AbstractCollisionResolutionExtension)));
	//		if (!resolution->isDefault()) {
	//			resolution->resolveCollision(_subject);
	//		}
	//		else {
	//			shared_ptr<AbstractCollisionResolutionExtension> resolution = dynamic_pointer_cast<AbstractCollisionResolutionExtension>(_subject->getExtension(typeid(AbstractCollisionResolutionExtension)));
	//			resolution->resolveCollision(obj);
	//		}

	//	}
	//}



}

