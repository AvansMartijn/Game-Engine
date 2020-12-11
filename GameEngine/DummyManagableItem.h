#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_DummyManagableItem __declspec(dllexport)
#else
#define GAMEENGINE_DummyManagableItem __declspec(dllimport)
#endif
#include "AbstractManageableItem.h"

class GAMEENGINE_DummyManagableItem DummyManagableItem : public AbstractManageableItem {
public:
	DummyManagableItem();

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
};

