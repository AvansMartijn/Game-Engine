#include "AllWeaponsCheat.h"
#include "Scene.h"

bool AllWeaponsCheat::Execute()
{
	if (Scene::getInstance().getPlayer()->hasExtension(typeid(CanWieldExtension))) {
		
		shared_ptr<AbstractManageableItem> glueItem = Scene::getInstance().getItem("GlueGun");
		glueItem->setAmmo(-1);
		glueItem->setCooldown(0);

		shared_ptr<AbstractManageableItem> thrusterItem = Scene::getInstance().getItem("ThrusterGun");
		thrusterItem->setAmmo(-1);
		thrusterItem->setCooldown(0);

		shared_ptr<AbstractManageableItem> portalItem = Scene::getInstance().getItem("PortalGun");
		portalItem->setAmmo(-1);
		portalItem->setCooldown(0);

		Scene::getInstance().getWieldExtension()->addItem(glueItem);
		Scene::getInstance().getWieldExtension()->addItem(thrusterItem);
		Scene::getInstance().getWieldExtension()->addItem(portalItem);
	}
	return true;
}