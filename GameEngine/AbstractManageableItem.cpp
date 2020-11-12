#include "pch.h"
#include "AbstractManageableItem.h"

AbstractManageableItem::AbstractManageableItem() {}

AbstractManageableItem::~AbstractManageableItem() {}

std::string AbstractManageableItem::getTextureKey() {
	return _textureKey;
}