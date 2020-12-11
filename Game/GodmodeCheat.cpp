#include "GodmodeCheat.h"
#include "Scene.h"
#include "HealthExtension.h"

bool GodmodeCheat::Execute() {
	if (Scene::getInstance().getPlayer()->hasExtension(typeid(HealthExtension))) {
		shared_ptr<HealthExtension> healthExtension = Scene::getInstance().getPlayer()->getExtension<HealthExtension>();
		healthExtension->setHealth(MAXINT);

		return true;
	}

	return false;
}
