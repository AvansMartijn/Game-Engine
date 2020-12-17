#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_PortalManagableItem __declspec(dllexport)
#else
#define GAMEENGINE_PortalManagableItem __declspec(dllimport)
#endif
#include "AbstractManageableItem.h"

class GAMEENGINE_PortalManagableItem PortalManagableItem : public AbstractManageableItem {
public:
	PortalManagableItem();

	/// <summary>
	/// When the left mouse button has been pressed.
	/// </summary>
	/// <param name="x">The x-coordinate.</param>
	/// <param name="y">The y-coordinate.</param>
	void onLeftClick(int x, int y);

	/// <summary>
	/// When the right mouse button has been pressed.
	/// </summary>
	/// <param name="x">The x-coordinate.</param>
	/// <param name="y">The y-coordinate.</param>
	void onRightClick(int x, int y);

	/// <summary>
	/// Shoots a portal.
	/// </summary>
	/// <param name="fixtureUserData">The portal sensor.</param>
	/// <param name="x">The x-coordinate.</param>
	/// <param name="y">The y-coordinate.</param>
	void shootPortal(std::string fixtureUserData, int x, int y);

	/// <summary>
	/// Clones the current item.
	/// </summary>
	/// <returns>A copy of the current item.</returns>
	std::unique_ptr<AbstractManageableItem> clone() const;
};

