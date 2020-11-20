#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_PortalManagableItem __declspec(dllexport)
#else
#define GAMEENGINE_PortalManagableItem __declspec(dllimport)
#endif
#include "AbstractManageableItem.h"

class GAMEENGINE_PortalManagableItem PortalManagableItem : public AbstractManageableItem
{
public:
	PortalManagableItem();

	void onLeftClick(int x, int y);
	void onRightClick(int x, int y);
	void shootPortal(std::string fixtureUserData, int x, int y);
};

