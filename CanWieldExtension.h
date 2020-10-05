#pragma once
#include "AbstractGameObjectExtension.h"
#include "AbstractManageableItem.h"
#include <vector>

class CanWieldExtension : AbstractGameObjectExtension
{
private:
	std::vector<AbstractManageableItem> items;

public:
	void addItem(AbstractManageableItem);
	void removeItem(AbstractManageableItem);
};

