#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_AbstractManageableItem __declspec(dllexport)
#else
#define GAMEENGINE_AbstractManageableItem __declspec(dllimport)
#endif
#include <string>
#include <memory>
#include "Window.h"
#include <chrono>

class GAMEENGINE_AbstractManageableItem AbstractManageableItem {
protected:
	std::string _textureKey;
	std::string _screenName;
	shared_ptr<GameObject> _owner;
	float _width;
	float _height;
	int _ammo;
	long _cooldown;
	std::chrono::steady_clock::time_point _lastUsed;
public:
	bool shouldRender;

	AbstractManageableItem();
	~AbstractManageableItem();

	/// <summary>
	/// Get's the texture key.
	/// </summary>
	/// <returns>The texture key.</returns>
	std::string getTextureKey();

	/// <summary>
	/// Get's the screen name.
	/// </summary>
	/// <returns>The screen name.</returns>
	std::string getScreenName();

	/// <summary>
	/// Get's the width.
	/// </summary>
	/// <returns>The width.</returns>
	float getWidth();

	/// <summary>
	/// Get's the height.
	/// </summary>
	/// <returns>The height.</returns>
	float getHeight();

	/// <summary>
	/// Get's the amount of ammo.
	/// </summary>
	/// <returns>The amount of ammo.</returns>
	int getAmmo();

	/// <summary>
	/// Get's the cooldown in ms.
	/// </summary>
	/// <returns>The cooldown in ms.</returns>
	long getCooldown();

	/// <summary>
	/// Get's the last used time in ms.
	/// </summary>
	/// <returns>The last used time in ms.</returns>
	long getLastUsed();

	/// <summary>
	/// Set's the amount of ammo.
	/// </summary>
	/// <param name="amount">The amount of ammo</param>
	void setAmmo(int amount);

	/// <summary>
	/// Set's the cooldown.
	/// </summary>
	/// <param name="cooldown">The cooldown we want to set.</param>
	void setCooldown(long cooldown);

	/// <summary>
	/// Set's the owner of this item.
	/// </summary>
	/// <param name="owner">The owner.</param>
	void setOwner(shared_ptr<GameObject> owner);

	/// <summary>
	/// Renders this item.
	/// </summary>
	/// <param name="window">The window we want to use.</param>
	virtual void render(const unique_ptr<Window>& window);

	/// <summary>
	/// When the left mouse button has been pressed.
	/// </summary>
	/// <param name="x">The x-coordinate.</param>
	/// <param name="y">The y-coordinate.</param>
	virtual void onLeftClick(int x, int y) = 0;

	/// <summary>
	/// When the right mouse button has been pressed.
	/// </summary>
	/// <param name="x">The x-coordinate.</param>
	/// <param name="y">The y-coordinate.</param>
	virtual void onRightClick(int x, int y) = 0;
};

