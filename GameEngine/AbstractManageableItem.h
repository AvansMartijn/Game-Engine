#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_AbstractManageableItem __declspec(dllexport)
#else
#define GAMEENGINE_AbstractManageableItem __declspec(dllimport)
#endif
#include <string>
#include <memory>
#include "Window.h"

class GAMEENGINE_AbstractManageableItem AbstractManageableItem
{
protected:
	std::string _textureKey;
	shared_ptr<GameObject> _owner;
	float _width;
	float _height;
public:
	AbstractManageableItem();
	~AbstractManageableItem();

	std::string getTextureKey();	
	float getWidth();
	float getHeight();
	void setOwner(shared_ptr<GameObject> owner);

	virtual void render(const unique_ptr<Window>& window);
	virtual void onLeftClick(int x, int y) = 0;
	virtual void onRightClick(int x, int y) = 0;

};

