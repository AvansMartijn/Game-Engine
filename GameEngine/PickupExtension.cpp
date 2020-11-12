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
	_subject->addTexture(0, _item->getTextureKey());
}