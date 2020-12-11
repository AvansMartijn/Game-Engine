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

class GAMEENGINE_AbstractManageableItem AbstractManageableItem
{
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
	AbstractManageableItem();
	~AbstractManageableItem();

	bool shouldRender;
	std::string getTextureKey();	
	std::string getScreemName();
	float getWidth();
	float getHeight();
	int getAmmo();
	long getCooldown();
	long getLastUsed();
	void setAmmo(int amount);
	void setCooldown(long amount);
	void setOwner(shared_ptr<GameObject> owner);

	virtual void render(const unique_ptr<Window>& window);
	virtual void onLeftClick(int x, int y) = 0;
	virtual void onRightClick(int x, int y) = 0;


};

