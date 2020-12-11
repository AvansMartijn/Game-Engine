#pragma once

#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_AssetRegistry __declspec(dllexport)
#else
#define GAMEENGINE_AssetRegistry __declspec(dllimport)
#endif

#include <map>
#include <SDL_image.h>
#include <iostream>
#include "dirent.h"
#include <vector>
#include "FileData.h"
#include <sstream>
#include "SDLTexture.h"

class Window;
class GAMEENGINE_AssetRegistry AssetRegistry {
private:
	AssetRegistry();

	static AssetRegistry instance;

	std::map<std::string, std::shared_ptr<SDLTexture>> _textures;
	std::map<std::string, std::string> _fonts;

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
	void registerTexture(std::string textureKey, std::shared_ptr<SDLTexture> texture);

	/// <summary>
	/// Get's the texture from the registry.
	/// </summary>
	/// <param name="textureKey">The texture key.</param>
	/// <returns>The texture.</returns>
	std::shared_ptr<SDLTexture> getTexture(std::string textureKey);

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
	/// Get's the base path.
	/// </summary>
	/// <returns>The base path.</returns>
	std::string getBasePath() const;

	/// <summary>
	/// Get's all file locations in the given directory.
	/// </summary>
	/// <param name="directory">The directory.</param>
	/// <param name="isDeep">If we should scan the directories within this directory.</param>
	/// <param name="shouldAddKey">If we should add the file name as key.</param>
	/// <returns>A list with all file data.</returns>
	std::vector<FileData> getFilesInDirectory(std::string directory, bool isDeep, bool shouldAddKey = true) const;

	/// <summary>
	/// Split a string by the given delimiter.
	/// </summary>
	/// <param name="string">The string we want to split.</param>
	/// <param name="delimiter">The character we want to use to split the string.</param>
	/// <returns>The parts of the split string.</returns>
	std::vector<std::string> split(std::string& string, char delimiter);

	/// <summary>
	/// Get's the pref dir from SDL.
	/// </summary>
	/// <param name="org">The organisation name.</param>
	/// <param name="app">The app name.</param>
	/// <returns>The pref dir.</returns>
	std::string getPrefPath(std::string org, std::string app);
};
