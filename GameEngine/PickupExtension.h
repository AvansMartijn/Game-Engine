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
	shared_ptr<AbstractManageableItem> _item;
public:
	PickupExtension();

	/// <summary>
	/// Set's the current item.
	/// </summary>
	/// <param name="item">The item we want to set.</param>
	void setItem(shared_ptr<AbstractManageableItem> item);

	/// <summary>
	/// Get's the current item.
	/// </summary>
	/// <returns></returns>
	shared_ptr<AbstractManageableItem> getItem();

	/// <summary>
	/// When an entity collides with game object which has this extension.
	/// </summary>
	/// <param name="gameObject">The colliding game object</param>
	void onEntityCollision(shared_ptr<GameObject> gameObject);

	static AbstractGameObjectExtension* __stdcall create() { return new PickupExtension(); }
};

