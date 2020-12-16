#include "pch.h"
#include "PickupExtension.h"

PickupExtension::PickupExtension() {
	type = getType();
}

AbstractManageableItem* PickupExtension::getItem() {
	return _item.get();
}

void PickupExtension::setItem(unique_ptr<AbstractManageableItem> item) {
	_item = std::move(item);
	_subject->texture = _item->getTextureKey();
}

void PickupExtension::onEntityCollision(shared_ptr<GameObject> gameObject) {
	for (const unique_ptr<AbstractManageableItem>& gun : Scene::getInstance().getPlayer()->getExtension<CanWieldExtension>()->getItems()) {
		if (_item->getTextureKey() == gun->getTextureKey()) {
			if (_item->getAmmo() == -1 || gun->getAmmo() == -1)
				gun->setAmmo(-1);
			else
				gun->setAmmo(gun->getAmmo() + _item->getAmmo());

			Physics::getInstance().deleteQueue.push_back(_subject->id);
			return;
		}
	}

	Scene::getInstance().getPlayer()->getExtension<CanWieldExtension>()->addItem(std::move(_item));
	Physics::getInstance().deleteQueue.push_back(_subject->id);
}


void PickupExtension::fillProperties(std::map<std::string, ExtensionProperty> extensionProperties) {
	AbstractManageableItem* itemBlueprint = Scene::getInstance().getItem(itemType);

	std::unique_ptr<AbstractManageableItem> item = itemBlueprint->clone();
	if (extensionProperties.find("ammo") != extensionProperties.end())
		item->setAmmo(extensionProperties["ammo"].valueInt);

	if (extensionProperties.find("cooldown") != extensionProperties.end())
		item->setCooldown(extensionProperties["cooldown"].valueInt);

	setItem(std::move(item));
}