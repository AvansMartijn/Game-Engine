#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_PickupExtension __declspec(dllexport)
#else
#define GAMEENGINE_PickupExtension __declspec(dllimport)
#endif
#include "AbstractGameObjectExtension.h"
#include "AbstractManageableItem.h"
#include "GameObject.h"

class GAMEENGINE_PickupExtension PickupExtension : public AbstractGameObjectExtension
{
private:
	shared_ptr<AbstractManageableItem> _item;
public:
	PickupExtension();

	void setItem(shared_ptr<AbstractManageableItem> item);
	shared_ptr<AbstractManageableItem> getItem();

	static AbstractGameObjectExtension* __stdcall create() { return new PickupExtension(); }
};

