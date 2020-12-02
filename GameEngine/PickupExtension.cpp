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
	Scene::getInstance().getWieldExtension()->addItem(_item);

	Physics::getInstance().deleteQueue.push_back(_subject->id);
}