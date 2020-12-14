#include "pch.h"
#include "CanWieldExtension.h"

CanWieldExtension::CanWieldExtension() {
	type = "CanWieldExtension";
}

void CanWieldExtension::addItem(std::shared_ptr<AbstractManageableItem> item) {
	item->setOwner(_subject);
	_items.push_back(item);
}

void CanWieldExtension::clearItems() {
	_items.clear();
}

std::shared_ptr<AbstractManageableItem> CanWieldExtension::getCurrentItem() {
	if (_currentItemIndex >= _items.size())
		return nullptr;
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
	std::shared_ptr<AbstractManageableItem> item = getCurrentItem();

	if (item != nullptr)
		getCurrentItem()->onLeftClick(x, y);
}

void CanWieldExtension::onRightClick(int x, int y) {
	std::shared_ptr<AbstractManageableItem> item = getCurrentItem();

	if (item != nullptr)
		getCurrentItem()->onRightClick(x, y);
}

bool CanWieldExtension::hasItems() {
	return _items.size() > 0;
}

void CanWieldExtension::setShouldRender(bool shouldRender) {
	if (hasItems())
		getCurrentItem()->shouldRender = shouldRender;
}

void CanWieldExtension::fillProperties(std::map<std::string, ExtensionProperty> extensionProperties) {}
