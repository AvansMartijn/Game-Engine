#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_AbstractManageableItem __declspec(dllexport)
#else
#define GAMEENGINE_AbstractManageableItem __declspec(dllimport)
#endif
#include <string>

class GAMEENGINE_AbstractManageableItem AbstractManageableItem
{
protected:
	std::string _textureKey;
public:
	AbstractManageableItem();
	~AbstractManageableItem();

	std::string getTextureKey();

	virtual void onLeftClick(int x, int y) = 0;
	virtual void onRightClick(int x, int y) = 0;
};

