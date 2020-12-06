#include "ContactListener.h"

void ContactListener::BeginContact(b2Contact* contact) {
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

	if ((valA->type == "finishSensor" && valB->type == "playerFixture") || 
		(valB->type == "finishSensor" && valA->type == "playerFixture")) {
		Scene::getInstance().gameOver = true;
	}
}

void ContactListener::EndContact(b2Contact* contact) {}