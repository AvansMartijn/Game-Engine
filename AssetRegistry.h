#pragma once
#include <map>
#include <SDL_render.h>
#include <iostream>
#include <SDL_image.h>
#include <SDL_ttf.h>

class Window;
class AssetRegistry
{
public:
	AssetRegistry();
	~AssetRegistry();

	void registerTexture(Window* window, std::string key, std::string texture);
	SDL_Texture* getTexture(std::string key);

	void registerFont(std::string key, std::string fontLocation);
	std::string getFontPath(std::string key);
private:
	std::map<std::string, SDL_Texture*> _textures;
	std::map<std::string, std::string> _fonts;
};

