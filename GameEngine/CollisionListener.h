#pragma once

#include <Box2D.h>
#include "GameObject.h"
#include "AbstractCollisionResolutionExtension.h"
#include "MoveExtension.h"

class CollisionListener : public b2ContactListener
{
public:

	void BeginContact(b2Contact* contact){


		b2Fixture* fixtureA = contact->GetFixtureA();
		b2Fixture* fixtureB = contact->GetFixtureB();
		
		//if playerFeetFixture, increase collision counter to know if player can jump
		//check for collision extensions on gameobject
		//perform collision extensions
			
	}

	void EndContact(b2Contact* contact) {
	
	}
};
