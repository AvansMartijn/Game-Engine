#include "MoveExtension.h"

void MoveExtension::move() {
	PhysicsFacade physics;
	physics.updatePosition(_subject);
}