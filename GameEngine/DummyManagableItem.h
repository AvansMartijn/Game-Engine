#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_DummyManagableItem __declspec(dllexport)
#else
#define GAMEENGINE_DummyManagableItem __declspec(dllimport)
#endif
#include "AbstractManageableItem.h"

class GAMEENGINE_DummyManagableItem DummyManagableItem : public AbstractManageableItem
{
public:
	DummyManagableItem();

	void onLeftClick(int x, int y);
	void onRightClick(int x, int y);
};

