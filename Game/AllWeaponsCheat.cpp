#include "AllWeaponsCheat.h"
#include "Scene.h"

bool AllWeaponsCheat::execute() {
	if (Scene::getInstance().getPlayer()->hasExtension(typeid(CanWieldExtension))) {		
		Scene::getInstance().getPlayer()->getExtension<CanWieldExtension>()->clearItems();

		unique_ptr<AbstractManageableItem> glueItem = Scene::getInstance().getItem("GlueGun")->clone();
		glueItem->setAmmo(-1);
		glueItem->setCooldown(0);

		unique_ptr<AbstractManageableItem> thrusterItem = Scene::getInstance().getItem("ThrusterGun")->clone();
		thrusterItem->setAmmo(-1);
		thrusterItem->setCooldown(0);

		unique_ptr<AbstractManageableItem> portalItem = Scene::getInstance().getItem("PortalGun")->clone();
		portalItem->setAmmo(-1);
		portalItem->setCooldown(0);

		Scene::getInstance().getPlayer()->getExtension<CanWieldExtension>()->addItem(std::move(glueItem));
		Scene::getInstance().getPlayer()->getExtension<CanWieldExtension>()->addItem(std::move(thrusterItem));
		Scene::getInstance().getPlayer()->getExtension<CanWieldExtension>()->addItem(std::move(portalItem));
	}
	return true;
}
