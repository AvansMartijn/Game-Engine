#include "FlyCheat.h"
#include "Scene.h"
#include "HealthExtension.h"

bool FlyCheat::Execute() {
	Scene::getInstance().getPlayer()->getExtension<MoveExtension>()->jumpCounter = MAXINT;

	return true;
}
