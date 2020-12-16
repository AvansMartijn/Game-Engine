#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_PickupExtension __declspec(dllexport)
#else
#define GAMEENGINE_PickupExtension __declspec(dllimport)
#endif
#include "AbstractGameObjectExtension.h"
#include "AbstractManageableItem.h"
#include "GameObject.h"
#include "Scene.h"
#include "Physics.h"

class GAMEENGINE_PickupExtension PickupExtension : public AbstractGameObjectExtension {
private:
	unique_ptr<AbstractManageableItem> _item;
public:
	PickupExtension();

	std::string itemType;

	/// <summary>
	/// Set's the current item.
	/// </summary>
	/// <param name="item">The item we want to set.</param>
	void setItem(unique_ptr<AbstractManageableItem> item);

	/// <summary>
	/// Get's the current item.
	/// </summary>
	/// <returns></returns>
	AbstractManageableItem* getItem();

	/// <summary>
	/// When an entity collides with game object which has this extension.
	/// </summary>
	/// <param name="gameObject">The colliding game object</param>
	void onEntityCollision(shared_ptr<GameObject> gameObject);

	/// <summary>
	/// Fills the extensions with the given properties.
	/// </summary>
	/// <param name="properties">The properties we want to use</param>
	void fillProperties(std::map<std::string, ExtensionProperty> properties);

	static AbstractGameObjectExtension* __stdcall create() { return new PickupExtension(); }

	static std::string __stdcall getType() { return "PickupExtension"; }

};

