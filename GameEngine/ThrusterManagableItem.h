#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_ThrusterManagableItem __declspec(dllexport)
#else
#define GAMEENGINE_ThrusterManagableItem __declspec(dllimport)
#endif
#include "AbstractManageableItem.h"

class GAMEENGINE_ThrusterManagableItem ThrusterManagableItem : public AbstractManageableItem {
public:
	ThrusterManagableItem();

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
	/// Clones the current item.
	/// </summary>
	/// <returns>A copy of the current item.</returns>
	shared_ptr<AbstractManageableItem> clone() const;
};

