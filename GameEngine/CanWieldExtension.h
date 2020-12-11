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

class GAMEENGINE_CanWieldExtension CanWieldExtension : public AbstractGameObjectExtension {
private:
	std::vector<std::shared_ptr<AbstractManageableItem>> _items;
	int _currentItemIndex;
public:
	CanWieldExtension();
	
	/// <summary>
	/// Add the item to the extension.
	/// </summary>
	/// <param name="item">The item we want to add.</param>
	void addItem(std::shared_ptr<AbstractManageableItem> item);

	/// <summary>
	/// Clear all the items currently wielded.
	/// </summary>
	void clearItems();

	/// <summary>
	/// Get's the current item.
	/// </summary>
	/// <returns>The current item.</returns>
	std::shared_ptr<AbstractManageableItem> getCurrentItem();

	/// <summary>
	/// Get's all available items.
	/// </summary>
	/// <returns>All available items.</returns>
	std::vector<std::shared_ptr<AbstractManageableItem>> getItems();

	/// <summary>
	/// Set's the current item index.
	/// </summary>
	/// <param name="index">The current item.</param>
	void setCurrentItemIndex(int index);

	/// <summary>
	/// When the left mouse button has been clicked.
	/// </summary>
	/// <param name="x">The x-coordinates.</param>
	/// <param name="y">The y-coordinates.</param>
	void onLeftClick(int x, int y);

	/// <summary>
	/// When the right mouse button has been clicked.
	/// </summary>
	/// <param name="x">The x-coordinates.</param>
	/// <param name="y">The y-coordinates.</param>
	void onRightClick(int x, int y);

	/// <summary>
	/// If the object has any items.
	/// </summary>
	/// <returns>If the object has any items</returns>
	bool hasItems();

	static AbstractGameObjectExtension* __stdcall create() { return new CanWieldExtension(); }
};

