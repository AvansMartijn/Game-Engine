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
	for (auto gun : Scene::getInstance().getWieldExtension()->getItems())
	{
		if (_item->getTextureKey() == gun->getTextureKey()) {
			gun->setAmmo(gun->getAmmo() + _item->getAmmo());
			Physics::getInstance().deleteQueue.push_back(_subject->id);
			return;
		}
	}
	Scene::getInstance().getWieldExtension()->addItem(_item);
	Physics::getInstance().deleteQueue.push_back(_subject->id);
}