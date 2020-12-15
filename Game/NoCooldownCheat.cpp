#include "NoCooldownCheat.h"
#include "Scene.h"

bool NoCooldownCheat::execute() {
	std::vector<std::shared_ptr<AbstractManageableItem>> guns = Scene::getInstance().getPlayer()->getExtension<CanWieldExtension>()->getItems();

	for (auto const& gun : guns)
		gun->setCooldown(0);

	return true;
}
