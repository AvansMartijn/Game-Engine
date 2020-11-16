#include "pch.h"
#include "AssetRegistry.h"
#include "Window.h"

AssetRegistry AssetRegistry::instance;

AssetRegistry::AssetRegistry() {}

void AssetRegistry::registerTexture(std::string textureKey, SDL_Texture* texture) {
	_textures.insert(std::pair<std::string, SDL_Texture*>(textureKey, texture));
}

void AssetRegistry::registerFont(std::string fontKey, std::string fontPath) {
	_fonts.insert(std::pair<std::string, std::string>(fontKey, fontPath));
}

SDL_Texture* AssetRegistry::getTexture(std::string textureKey) {
	return _textures[textureKey];
}

std::string AssetRegistry::getFontPath(std::string fontKey) {
	return _fonts[fontKey];
}

void AssetRegistry::registerMusicTrack(const std::string& musicTrackKey, Mix_Music* musicTrack)
{
	_musicTracks.insert(std::pair<std::string, Mix_Music*>(musicTrackKey, musicTrack));
}

Mix_Music* AssetRegistry::getMusicTrack(const std::string& musicTrackKey)
{
	return _musicTracks[musicTrackKey];
}
