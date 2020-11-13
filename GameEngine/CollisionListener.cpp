#include "CollisionListener.h"
#include "pch.h"
#include "Physics.h"

void CollisionListener::BeginContact(b2Contact* contact) {
	b2Fixture* fixtureA = contact->GetFixtureA();
	b2Fixture* fixtureB = contact->GetFixtureB();

	b2Body* bodyA = fixtureA->GetBody();
	b2Body* bodyB = fixtureB->GetBody();

	CustomUserData* valA = (CustomUserData*)fixtureA->GetUserData().pointer;
	CustomUserData* valB = (CustomUserData*)fixtureB->GetUserData().pointer;

	CustomUserData* objA = (CustomUserData*)bodyA->GetUserData().pointer;
	CustomUserData* objB = (CustomUserData*)bodyB->GetUserData().pointer;

	shared_ptr<GameObject> gameObjectA = Scene::getInstance().getGameObject(objA->index);
	shared_ptr<GameObject> gameObjectB = Scene::getInstance().getGameObject(objB->index);

	//if playerFeetFixture, increase collision counter to know if player can jump
	if (valA != nullptr) {
		if (valA->type == "jumpSensor")
			Scene::getInstance().getPlayerMoveExtension()->jumpCounter++;

		if (valA->type == "exitSensor") {
			if (valB != nullptr) {
				if (valB->type == "playerFixture")
					Scene::getInstance().gameOver = true;
			}
		}

		if (valA->type == "pickupSensor") {
			if (valB != nullptr && valB->type == "playerFixture") {
				if (gameObjectA->hasExtension(typeid(PickupExtension)))
					dynamic_pointer_cast<PickupExtension>(gameObjectA->getExtension(typeid(PickupExtension)))->onEntityCollision(gameObjectB);
			}
		}
	}

	if (valB != nullptr) {
		if (valB->type == "jumpSensor")
			Scene::getInstance().getPlayerMoveExtension()->jumpCounter++;

		if (valB->type == "exitSensor") {
			if (valA != nullptr) {
				if (valA->type == "playerFixture")
					Scene::getInstance().gameOver = true;
			}
		}

		if (valB->type == "pickupSensor") {
			if (valA != nullptr && valA->type == "playerFixture") {
				if(gameObjectB->hasExtension(typeid(PickupExtension)))
					dynamic_pointer_cast<PickupExtension>(gameObjectB->getExtension(typeid(PickupExtension)))->onEntityCollision(gameObjectA);
			}
		}
	}

	//TODO:: Fix shared pointers

	if (gameObjectA != nullptr) {
		if (gameObjectA->hasExtension(typeid(AbstractCollisionResolutionExtension))) {
			shared_ptr<AbstractCollisionResolutionExtension> resolution = dynamic_pointer_cast<AbstractCollisionResolutionExtension>(gameObjectA->getExtension(typeid(AbstractCollisionResolutionExtension)));
			if (!resolution->isDefault()) {
				if (gameObjectB != nullptr) {
					if (gameObjectB->body.b2body->GetType() == b2_dynamicBody)
						resolution->resolveCollision(gameObjectB);
				}
			}
		}

	}

	if (gameObjectB != nullptr) {
		if (gameObjectB->hasExtension(typeid(AbstractCollisionResolutionExtension))) {
			shared_ptr<AbstractCollisionResolutionExtension> resolution = dynamic_pointer_cast<AbstractCollisionResolutionExtension>(gameObjectB->getExtension(typeid(AbstractCollisionResolutionExtension)));
			if (!resolution->isDefault()) {
				if (gameObjectA != nullptr) {
					if (gameObjectA->body.b2body->GetType() == b2_dynamicBody)
						resolution->resolveCollision(gameObjectA);
				}
			}
		}
	}

	
}

void CollisionListener::EndContact(b2Contact* contact) {
	b2Fixture* fixtureA = contact->GetFixtureA();
	b2Fixture* fixtureB = contact->GetFixtureB();

	b2Body* bodyA = fixtureA->GetBody();
	b2Body* bodyB = fixtureB->GetBody();

	CustomUserData* valA = (CustomUserData*)fixtureA->GetUserData().pointer;
	CustomUserData* valB = (CustomUserData*)fixtureB->GetUserData().pointer;

	GameObject* objA = (GameObject*)bodyA->GetUserData().pointer;
	GameObject* objB = (GameObject*)bodyB->GetUserData().pointer;

	if (valA != nullptr) {
		if (valA->type == "jumpSensor")
			Scene::getInstance().getPlayerMoveExtension()->jumpCounter--;
	}

	if (valB != nullptr) {
		if (valB->type == "jumpSensor")
			Scene::getInstance().getPlayerMoveExtension()->jumpCounter--;
	}
}