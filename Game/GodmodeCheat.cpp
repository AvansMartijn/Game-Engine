#include "GodmodeCheat.h"
#include "Scene.h"
#include "HealthExtension.h"

bool GodmodeCheat::execute() {
	if (Scene::getInstance().getPlayer()->hasExtension(typeid(HealthExtension))) {
		HealthExtension* healthExtension = Scene::getInstance().getPlayer()->getExtension<HealthExtension>();
		healthExtension->setHealth(MAXINT);

		return true;
	}

	return false;
}
