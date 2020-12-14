#include "pch.h"
#include "PickupExtension.h"

PickupExtension::PickupExtension() {
	type = "PickupExtension";
}

shared_ptr<AbstractManageableItem> PickupExtension::getItem() {
	return _item;
}

void PickupExtension::setItem(shared_ptr<AbstractManageableItem> item) {
	_item = item;
	_subject->texture = _item->getTextureKey();
}

void PickupExtension::onEntityCollision(shared_ptr<GameObject> gameObject) {
	for (auto gun : Scene::getInstance().getPlayer()->getExtension<CanWieldExtension>()->getItems()) {
		if (_item->getTextureKey() == gun->getTextureKey()) {
			if (_item->getAmmo() == -1 || gun->getAmmo() == -1)
				gun->setAmmo(-1);
			else
				gun->setAmmo(gun->getAmmo() + _item->getAmmo());

			Physics::getInstance().deleteQueue.push_back(_subject->id);
			return;
		}
	}

	Scene::getInstance().getPlayer()->getExtension<CanWieldExtension>()->addItem(_item);
	Physics::getInstance().deleteQueue.push_back(_subject->id);
}


void PickupExtension::fillProperties(std::map<std::string, ExtensionProperty> extensionProperties) {
	shared_ptr<AbstractManageableItem> itemBlueprint = Scene::getInstance().getItem(itemType);

	std::shared_ptr<AbstractManageableItem> item = itemBlueprint->clone();
	if (extensionProperties.find("ammo") != extensionProperties.end())
		item->setAmmo(extensionProperties["ammo"].valueInt);

	if (extensionProperties.find("cooldown") != extensionProperties.end())
		item->setCooldown(extensionProperties["cooldown"].valueInt);

	setItem(item);
}