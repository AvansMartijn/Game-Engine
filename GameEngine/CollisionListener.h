#pragma once


#include <Box2D.h>
#include "Physics.h"
#include "GameObject.h"
#include "AbstractCollisionResolutionExtension.h"
#include "MoveExtension.h"
#include "CustomUserData.h"

//class Physics;

class CollisionListener : public b2ContactListener
{
public:

	void BeginContact(b2Contact* contact) {


		b2Fixture* fixtureA = contact->GetFixtureA();
		b2Fixture* fixtureB = contact->GetFixtureB();

		b2Body* bodyA = fixtureA->GetBody();
		b2Body* bodyB = fixtureB->GetBody();

		CustomUserData* valA = (CustomUserData*)fixtureA->GetUserData().pointer;
		CustomUserData* valB = (CustomUserData*)fixtureB->GetUserData().pointer;

		GameObject* objA = (GameObject*)bodyA->GetUserData().pointer;
		GameObject* objB = (GameObject*)bodyB->GetUserData().pointer;


		//if playerFeetFixture, increase collision counter to know if player can jump
		if (valA != nullptr) {
			if (valA->type == "jumpSensor") {
				//Physics::getInstance().IncreaseCanJumpCounter();
			}
		}

		if (valB != nullptr) {
			if (valB->type == "jumpSensor") {
				//Physics::getInstance().IncreaseCanJumpCounter();
			}
		}

		//TODO:: Fix shared pointers 
		if (objA != nullptr) {
			if (objA->hasExtension(typeid(AbstractCollisionResolutionExtension))) {
				shared_ptr<AbstractCollisionResolutionExtension> resolution = dynamic_pointer_cast<AbstractCollisionResolutionExtension>(objA->getExtension(typeid(AbstractCollisionResolutionExtension)));
				if (!resolution->isDefault()) {
					if (objB != nullptr) {
						if (objB->body.b2body->GetType() == b2_dynamicBody) {
							shared_ptr<GameObject> jood1(objB);
							resolution->resolveCollision(jood1);
						}
					}
				}
			}
		}

		if (objB != nullptr) {
			if (objB->hasExtension(typeid(AbstractCollisionResolutionExtension))) {
				shared_ptr<AbstractCollisionResolutionExtension> resolution = dynamic_pointer_cast<AbstractCollisionResolutionExtension>(objB->getExtension(typeid(AbstractCollisionResolutionExtension)));
				if (!resolution->isDefault()) {
					if (objA != nullptr) {
						if (objA->body.b2body->GetType() == b2_dynamicBody) {
							shared_ptr<GameObject> jood(objA);
							resolution->resolveCollision(jood);
						}
					}
				}
			}
		}
	}
	//check for collision extensions on gameobject
	//perform collision extensions

	void EndContact(b2Contact* contact) {
		b2Fixture* fixtureA = contact->GetFixtureA();
		b2Fixture* fixtureB = contact->GetFixtureB();

		b2Body* bodyA = fixtureA->GetBody();
		b2Body* bodyB = fixtureB->GetBody();

		CustomUserData* valA = (CustomUserData*)fixtureA->GetUserData().pointer;
		CustomUserData* valB = (CustomUserData*)fixtureB->GetUserData().pointer;

		GameObject* objA = (GameObject*)bodyA->GetUserData().pointer;
		GameObject* objB = (GameObject*)bodyB->GetUserData().pointer;

		if (valA != nullptr) {
			if (valA->type == "jumpSensor") {
				//Physics::getInstance().DecreaseCanJumpCounter();
			}
		}

		if (valB != nullptr) {
			if (valB->type == "jumpSensor") {
				//Physics::getInstance().DecreaseCanJumpCounter();
			}
		}
	}
};
