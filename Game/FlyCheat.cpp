#include "FlyCheat.h"
#include "Scene.h"
#include "HealthExtension.h"

bool FlyCheat::execute() {
	Scene::getInstance().getPlayer()->getExtension<MoveExtension>()->jumpCounter = MAXINT;

	return true;
}
