#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_ThrusterManagableItem __declspec(dllexport)
#else
#define GAMEENGINE_ThrusterManagableItem __declspec(dllimport)
#endif
#include "AbstractManageableItem.h"

class GAMEENGINE_ThrusterManagableItem ThrusterManagableItem : public AbstractManageableItem
{
public:
	ThrusterManagableItem();

	void onLeftClick(int x, int y);
	void onRightClick(int x, int y);
};

