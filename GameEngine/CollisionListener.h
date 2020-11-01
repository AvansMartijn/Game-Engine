#pragma once

#include <Box2D.h>
#include "GameObject.h"
#include "AbstractCollisionResolutionExtension.h"

class CollisionListener : public b2ContactListener
{
public:

	void BeginContact(b2Contact* contact){
		/*b2Fixture* fixtureA = contact->GetFixtureA();
		b2Fixture* fixtureB = contact->GetFixtureB();

		b2Body* bodyA = fixtureA->GetBody();
		b2Body* bodyB = fixtureB->GetBody();

		GameObject* objA = (GameObject*)bodyA->GetUserData();
		GameObject* objB = (GameObject*)bodyB->GetUserData();*/

		//if (objA->hasExtension(typeid(AbstractCollisionResolutionExtension))) {
		//	shared_ptr<AbstractCollisionResolutionExtension> resolution = dynamic_pointer_cast<AbstractCollisionResolutionExtension>(objA->getExtension(typeid(AbstractCollisionResolutionExtension)));
		//	if (!resolution->isDefault()) {
		//		shared_ptr<GameObject> sharedobj(objB);
		//		resolution->resolveCollision(sharedobj);
		//	}
		//}
		//if (objB->hasExtension(typeid(AbstractCollisionResolutionExtension))) {
		//	shared_ptr<AbstractCollisionResolutionExtension> resolution = dynamic_pointer_cast<AbstractCollisionResolutionExtension>(objB->getExtension(typeid(AbstractCollisionResolutionExtension)));
		//	if (!resolution->isDefault()) {
		//		shared_ptr<GameObject> sharedobj(objA);
		//		resolution->resolveCollision(sharedobj);
		//	}
		//}

	}
};
