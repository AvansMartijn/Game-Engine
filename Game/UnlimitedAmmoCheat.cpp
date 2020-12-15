#include "UnlimitedAmmoCheat.h"
#include "Scene.h"

bool UnlimitedAmmoCheat::execute() {
	std::vector<std::shared_ptr<AbstractManageableItem>> guns = Scene::getInstance().getPlayer()->getExtension<CanWieldExtension>()->getItems();

	for (auto const& gun : guns)
		gun->setAmmo(-1);

	return true;
}
