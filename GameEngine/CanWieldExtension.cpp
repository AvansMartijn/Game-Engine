#include "pch.h"
#include "CanWieldExtension.h"

CanWieldExtension::CanWieldExtension() {
	type = "CanWieldExtension";
}

void CanWieldExtension::addItem(std::shared_ptr<AbstractManageableItem> item) {
	_items.push_back(item);
}

void CanWieldExtension::clearItems() {
	_items.clear();
}

std::shared_ptr<AbstractManageableItem> CanWieldExtension::getCurrentItem() {
	return _items[_currentItemIndex];
}

std::vector<std::shared_ptr<AbstractManageableItem>> CanWieldExtension::getItems() {
	return _items;
}

void CanWieldExtension::setCurrentItemIndex(int index) {
	if (index >= _items.size())
		return;

	_currentItemIndex = index;
}

void CanWieldExtension::onLeftClick(int x, int y) {
	getCurrentItem()->onLeftClick(x, y);
}

void CanWieldExtension::onRightClick(int x, int y) {
	getCurrentItem()->onRightClick(x, y);
}