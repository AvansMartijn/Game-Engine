#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_CanWieldExtension __declspec(dllexport)
#else
#define GAMEENGINE_CanWieldExtension __declspec(dllimport)
#endif
#include "AbstractGameObjectExtension.h"
#include "MovementType.h"

#include "AbstractGameObjectExtension.h"
#include "AbstractManageableItem.h"
#include <vector>

class GAMEENGINE_CanWieldExtension CanWieldExtension : public AbstractGameObjectExtension
{
private:
	std::vector<std::shared_ptr<AbstractManageableItem>> _items;
	int _currentItemIndex;
public:
	CanWieldExtension();
	void addItem(std::shared_ptr<AbstractManageableItem> item);
	void clearItems();

	std::shared_ptr<AbstractManageableItem> getCurrentItem();
	std::vector<std::shared_ptr<AbstractManageableItem>> getItems();

	void onLeftClick(int x, int y);
	void onRightClick(int x, int y);

	static AbstractGameObjectExtension* __stdcall create() { return new CanWieldExtension(); }
};

