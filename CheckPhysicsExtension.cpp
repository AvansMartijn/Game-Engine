#include "CheckPhysicsExtension.h"
#include "CollisionResolutionDefaultExtension.h"

CheckPhysicsExtension::CheckPhysicsExtension() {
	type = "CheckPhysicsExtension";
}

void CheckPhysicsExtension::doPhysics(vector<shared_ptr<GameObject>> gameObjectList)
{
	vector<shared_ptr<GameObject>> collisionList = _physicsfacade.getCollisions(_subject, gameObjectList);
	for (auto& obj : collisionList) {

		//if (obj != _subject) {
			std::cout << "collidesWithOther\n";
			if (obj->hasExtension(typeid(AbstractCollisionResolutionExtension))) {
				shared_ptr<AbstractCollisionResolutionExtension> resolution = dynamic_pointer_cast<AbstractCollisionResolutionExtension>(obj->getExtension(typeid(AbstractCollisionResolutionExtension)));
				if (!resolution->isDefault()) {
					resolution->resolveCollision( obj, _subject);
					//shared_ptr<AbstractCollisionResolutionExtension> collisionResolutionExtension = dynamic_pointer_cast<AbstractCollisionResolutionExtension>(obj->getExtension(typeid(AbstractCollisionResolutionExtension)));
					//collisionResolutionExtension(shared_ptr<GameObject> obj, shared_ptr<GameObject> _subject);
				}
				else {
					shared_ptr<AbstractCollisionResolutionExtension> resolution = dynamic_pointer_cast<AbstractCollisionResolutionExtension>(_subject->getExtension(typeid(AbstractCollisionResolutionExtension)));
					resolution->resolveCollision(obj, _subject);
				}
			
			}
		//}
		//if special collisionExtension, perform special extension
	}
}
