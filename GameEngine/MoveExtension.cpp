#include "pch.h"
#include "MoveExtension.h"

MoveExtension::MoveExtension()
{
	type = "MoveExtension";
}

void MoveExtension::move() {
	//_physicsFacade.updatePosition(_subject);
}

bool MoveExtension::canJump() {
	return jumpCounter > 0;
}

void MoveExtension::reset() {
	jumpCounter = 0;
}