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

		CustomUserData* objA = (CustomUserData*)bodyA->GetUserData().pointer;
		CustomUserData* objB = (CustomUserData*)bodyB->GetUserData().pointer;

		shared_ptr<GameObject> gameObjectA = Physics::getInstance().getGameObject(objA->index);
		shared_ptr<GameObject> gameObjectB = Physics::getInstance().getGameObject(objB->index);


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

		if (gameObjectA != nullptr) {
			if (gameObjectA->hasExtension(typeid(AbstractCollisionResolutionExtension))) {
				shared_ptr<AbstractCollisionResolutionExtension> resolution = dynamic_pointer_cast<AbstractCollisionResolutionExtension>(gameObjectA->getExtension(typeid(AbstractCollisionResolutionExtension)));
				if (!resolution->isDefault()) {
					if (gameObjectB != nullptr) {
						if (gameObjectB->body.b2body->GetType() == b2_dynamicBody) {
							resolution->resolveCollision(gameObjectB);
						}
					}
				}
			}
		}

		if (gameObjectB != nullptr) {
			if (gameObjectB->hasExtension(typeid(AbstractCollisionResolutionExtension))) {
				shared_ptr<AbstractCollisionResolutionExtension> resolution = dynamic_pointer_cast<AbstractCollisionResolutionExtension>(gameObjectB->getExtension(typeid(AbstractCollisionResolutionExtension)));
				if (!resolution->isDefault()) {
					if (gameObjectA != nullptr) {
						if (gameObjectA->body.b2body->GetType() == b2_dynamicBody) {
							resolution->resolveCollision(gameObjectA);
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
