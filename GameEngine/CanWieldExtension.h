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
	std::vector<std::unique_ptr<AbstractManageableItem>> _items;
	int _currentItemIndex;
public:
	CanWieldExtension();
	CanWieldExtension(const CanWieldExtension&) = delete;
	CanWieldExtension& operator =(const CanWieldExtension&) = delete;

	/// <summary>
	/// Add the item to the extension.
	/// </summary>
	/// <param name="item">The item we want to add.</param>
	void addItem(std::unique_ptr<AbstractManageableItem> item);

	/// <summary>
	/// Clear all the items currently wielded.
	/// </summary>
	void clearItems();

	// REASON: It's possible for the item to be a nullptr, that's why a reference is returned. 
	/// <summary>
	/// Get's the current item.
	/// </summary>
	/// <returns>The current item.</returns>
	AbstractManageableItem* getCurrentItem();

	/// <summary>
	/// Get's all available items.
	/// </summary>
	/// <returns>All available items.</returns>
	std::vector<std::unique_ptr<AbstractManageableItem>>& getItems();

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

	/// <summary>
	/// Set's if the current item should render.
	/// </summary>
	/// <param name="shouldRender">If the current item should render</param>
	void setShouldRender(bool shouldRender);

	/// <summary>
	/// Fills the extensions with the given properties.
	/// </summary>
	/// <param name="properties">The properties we want to use</param>
	void fillProperties(std::map<std::string, ExtensionProperty> properties);

	static AbstractGameObjectExtension* __stdcall create() { return new CanWieldExtension(); }

	static std::string __stdcall getType() { return "CanWieldExtension"; }
};

