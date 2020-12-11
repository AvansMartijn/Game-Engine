#include "FlyCheat.h"
#include "Scene.h"
#include "HealthExtension.h"

bool FlyCheat::Execute() {
	Scene::getInstance().getPlayerMoveExtension()->jumpCounter = MAXINT;
	return true;
}
