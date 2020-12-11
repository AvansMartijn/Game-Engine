#include "UnlimitedAmmoCheat.h"
#include "Scene.h"

bool UnlimitedAmmoCheat::Execute()
{
	std::vector<std::shared_ptr<AbstractManageableItem>> guns = Scene::getInstance().getWieldExtension()->getItems();

	for (auto const& gun : guns)
	{
		gun->setAmmo(-1);
	}
	return true;
}
