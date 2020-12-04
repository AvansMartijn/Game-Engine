#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_GlueManagableItem __declspec(dllexport)
#else
#define GAMEENGINE_GlueManagableItem __declspec(dllimport)
#endif
#include "AbstractManageableItem.h"

class GAMEENGINE_GlueManagableItem GlueManagableItem : public AbstractManageableItem
{
public:
	GlueManagableItem();

	void onLeftClick(int x, int y);
	void onRightClick(int x, int y);
};

