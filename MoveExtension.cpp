#include "MoveExtension.h"

MoveExtension::MoveExtension()
{
	type = "MoveExtension";
}

void MoveExtension::move() {
	PhysicsFacade physics;
	physics.updatePosition(_subject);
}