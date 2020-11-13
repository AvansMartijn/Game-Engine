#pragma once


#include <Box2D.h>
#include "GameObject.h"
#include "AbstractCollisionResolutionExtension.h"
#include "MoveExtension.h"
#include "CustomUserData.h"
#include "PickupExtension.h"

class Physics;
class CollisionListener : public b2ContactListener
{
public:
	void BeginContact(b2Contact* contact);

	void EndContact(b2Contact* contact);
};
