#include "NoCooldownCheat.h"
#include "Scene.h"

bool NoCooldownCheat::Execute()
{
	std::vector<std::shared_ptr<AbstractManageableItem>> guns = Scene::getInstance().getWieldExtension()->getItems();

	for (auto const& gun : guns)
	{
		gun->setCooldown(0);
	}
	return true;
}
