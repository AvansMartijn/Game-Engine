#pragma once

#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_AssetRegistry __declspec(dllexport)
#else
#define GAMEENGINE_AssetRegistry __declspec(dllimport)
#endif

#include <map>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <iostream>

class Window;
class GAMEENGINE_AssetRegistry AssetRegistry
{
private:
	AssetRegistry();

	static AssetRegistry instance;

	std::map<std::string, SDL_Texture*> _textures;
	std::map<std::string, std::string> _fonts;
	std::map<std::string, Mix_Music*> _musicTracks;
	std::map<std::string, Mix_Chunk*> _sfx;
public:
	static AssetRegistry& getInstance() { return instance; }

	AssetRegistry(const AssetRegistry&) = delete;
	AssetRegistry(AssetRegistry&&) = delete;
	AssetRegistry& operator=(const AssetRegistry&) = delete;
	AssetRegistry& operator=(AssetRegistry&&) = delete;

	/// <summary>
	/// Adds a texture to the registry.
	/// </summary>
	/// <param name="textureKey">The texture key.</param>
	/// <param name="texture">The texture.</param>
	void registerTexture(std::string textureKey, SDL_Texture* texture);

	/// <summary>
	/// Get's the texture from the registry.
	/// </summary>
	/// <param name="textureKey">The texture key.</param>
	/// <returns>The texture.</returns>
	SDL_Texture* getTexture(std::string textureKey);

	/// <summary>
	/// Adds the font path to the registry.
	/// </summary>
	/// <param name="fontKey">The font key.</param>
	/// <param name="fontPath">The font.</param>
	void registerFont(std::string fontKey, std::string fontPath);

	/// <summary>
	/// Get's the font path from the registry.
	/// </summary>
	/// <param name="fontKey">The font key.</param>
	/// <returns>The font path.</returns>
	std::string getFontPath(std::string fontKey);

	/// <summary>
	/// Adds the music track to the registry.
	/// </summary>
	/// <param name="musicTrackKey">The track key</param>
	/// <param name="musicTrack">The music track</param>
	void registerMusicTrack(const std::string& musicTrackKey, Mix_Music* musicTrack);

	/// <summary>
	/// Gets the music track from the registry
	/// </summary>
	/// <param name="musicTrackKey">The track key</param>
	/// <returns></returns>
	Mix_Music* getMusicTrack(const std::string& musicTrackKey);
};

