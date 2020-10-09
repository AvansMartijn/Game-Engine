#include "CheckPhysicsExtension.h"
#include "CollisionResolutionDefaultExtension.h"

void CheckPhysicsExtension::doPhysics(vector<shared_ptr<GameObject>> gameObjectList)
{
	vector<shared_ptr<GameObject>> collisionList = _physicsfacade.getCollisions(_subject, gameObjectList);
	for (auto& obj : collisionList) {

		if (obj->hasExtension(typeid(AbstractCollisionResolutionExtension))) {
			shared_ptr<AbstractCollisionResolutionExtension> resolution = dynamic_pointer_cast<AbstractCollisionResolutionExtension>(obj->getExtension(typeid(AbstractCollisionResolutionExtension)));
			if (!resolution->isDefault()) {
				resolution->resolveCollition( obj,_subject);
				//shared_ptr<AbstractCollisionResolutionExtension> collisionResolutionExtension = dynamic_pointer_cast<AbstractCollisionResolutionExtension>(obj->getExtension(typeid(AbstractCollisionResolutionExtension)));
				//collisionResolutionExtension(shared_ptr<GameObject> obj, shared_ptr<GameObject> _subject);
			}
		}
		//if special collisionExtension, perform special extension
	}
}
