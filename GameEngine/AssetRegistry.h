#pragma once

#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_AssetRegistry __declspec(dllexport)
#else
#define GAMEENGINE_AssetRegistry __declspec(dllimport)
#endif

#include <map>
#include <SDL_image.h>
#include <iostream>

class Window;
class GAMEENGINE_AssetRegistry AssetRegistry
{
public:
	AssetRegistry();
	~AssetRegistry();

	void registerTexture(std::string textureKey, SDL_Texture* texture);
	SDL_Texture* getTexture(std::string textureKey);

	void registerFont(std::string fontKey, std::string fontPath);
	std::string getFontPath(std::string fontKey);
private:
	std::map<std::string, SDL_Texture*> _textures;
	std::map<std::string, std::string> _fonts;
};

