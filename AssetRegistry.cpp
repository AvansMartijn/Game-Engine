#include "AssetRegistry.h"
#include "Window.h"

AssetRegistry::AssetRegistry() {

}

AssetRegistry::~AssetRegistry() {

}

void AssetRegistry::registerTexture(Window* window, std::string key, std::string filePath) {
	_textures.insert(std::pair<std::string, SDL_Texture*>(key, window->getTexture(filePath)));
}

SDL_Texture* AssetRegistry::getTexture(std::string key) {
	return _textures[key];
}

void AssetRegistry::registerFont(std::string key, std::string fontPath) {
	_fonts.insert(std::pair<std::string, std::string> (key, fontPath));
}

std::string AssetRegistry::getFontPath(std::string key) {
	return _fonts[key];
}